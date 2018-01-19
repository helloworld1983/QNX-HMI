#include "RendererControl.h"

#include "services/VideoPlayer.h"

#include "windowmanager/WindowManager.h"
#include "util/Util.h"
#include "ApplicationManager.h"
#include "Core.h"

#include <QProcess>
#include "iostream"

static const int ZORDER_SHOW = 20;
static const int ZORDER_HIDE = -1;

RendererControl::RendererControl(QnxCar::VideoPlayer *videoPlayer,
                                 QObject *parent)
    : QObject(parent)
    , m_videoPlayer(videoPlayer)
{
    Q_ASSERT(videoPlayer);

    //    connect(Core::self()->windowManager(), SIGNAL(windowPosted(Q_PID)), SLOT(handleWindowPosted(Q_PID)));
    connect(videoPlayer, SIGNAL(viewPortChanged(QRect)), SLOT(handleVideoPlayerChanged()));
    connect(videoPlayer, SIGNAL(stateChanged(QnxCar::VideoPlayer::State)), SLOT(handleVideoPlayerChanged()));
    //    connect(videoPlayer, &QnxCar::VideoPlayer::videoPixelWidthChanged, this, &RendererControl::updateVideoWindow);
    //    connect(videoPlayer, &QnxCar::VideoPlayer::videoPixelHeightChanged, this, &RendererControl::updateVideoWindow);

    // try to retrieve the PID of the
    m_rendererPid = retrieveRendererPid();
    if (!m_rendererPid) {
        qWarning() << Q_FUNC_INFO << "Failed to retrieve PID of mm-renderer, VideoPlayer will not function!";
    } else {
        Core::self()->applicationManager()->addToUnmanagedProcesses(m_rendererPid);
    }

    windowManager = Core::self()->windowManager();
    windowManager->setZValue(m_rendererPid, ZORDER_HIDE);
}

Q_PID RendererControl::rendererPid() const
{
    return m_rendererPid;
}

Q_PID RendererControl::retrieveRendererPid() const
{
    const QString program = QStringLiteral("pidin");
    QStringList arguments;
    arguments << QStringLiteral("-P") << QStringLiteral("mm-renderer");
    arguments << QStringLiteral("-F") << QStringLiteral("%a");

    QProcess process;
    process.start(program, arguments);
    bool success = process.waitForFinished(3000);
    if (!success)
        return 0;

    const QByteArray result = process.readAllStandardOutput();
    const QList<QByteArray> lines = result.split('\n');
    // lines should look like: ("     pid", " 1679413", "")
    if (lines.size() != 3)
        return 0;

    return lines[1].toInt();
}

QnxCar::VideoPlayer *RendererControl::videoPlayer() const
{
    return m_videoPlayer;
}

void RendererControl::handleWindowPosted(Q_PID pid)
{
    if (!m_rendererPid)
        return;

    if (pid == m_rendererPid) {
        car2_debug() << "Startup of video renderer window catched, applying viewport constraints";
        updateVideoWindow();
    }
}

void RendererControl::handleVideoPlayerChanged()
{
    updateVideoWindow();
}

// Returns the largest possible rectangle centered inside containingRect with the aspect ratio defined by videoWidth and videoHeight
static QRect calculateActualViewport(const QRect &containingRect, int videoWidth, int videoHeight)
{
    const QSize fitSize = QSize(videoWidth, videoHeight).scaled(containingRect.size(), Qt::KeepAspectRatio);
    const int xOffset = (containingRect.width() - fitSize.width()) / 2;
    const int yOffset = (containingRect.height() - fitSize.height()) / 2;
    return QRect(containingRect.topLeft() + QPoint(xOffset, yOffset), fitSize);
}

void RendererControl::updateVideoWindow()
{
    Q_ASSERT(m_videoPlayer);

    if (!m_rendererPid){
        return;
    }

    const QnxCar::VideoPlayer::State state = m_videoPlayer->state();
    const QRect viewPort = m_videoPlayer->viewPort();

    int position_x1 = viewPort.x();
    int position_y1 = viewPort.y();
    int position_x2 = viewPort.x() + viewPort.width();
    int position_y2 = viewPort.y() + viewPort.height();

    if(position_x1 < 0 || position_y1 < 0 || position_x2 > 1200 || position_y2 > 1920) {
        qDebug() << "Invalid geometry, exit";
        return;
    }

    if(viewPort.width() > 1200 || viewPort.height() > 784) {
        qDebug() << "Invalid size, exit";
        return;
    }

    if (state == QnxCar::VideoPlayer::PlayingState && viewPort.isValid()) {

        windowManager->setZValue(m_rendererPid, ZORDER_HIDE);
        windowManager->setGeometry(m_rendererPid, viewPort);
        windowManager->setZValue(m_rendererPid, ZORDER_SHOW);
        std::cout << "set video geometry ok" << std::endl;
    } else {
        windowManager->setZValue(m_rendererPid, ZORDER_HIDE);
        std::cout << "Hide viewPort" << std::endl;

    }
}
