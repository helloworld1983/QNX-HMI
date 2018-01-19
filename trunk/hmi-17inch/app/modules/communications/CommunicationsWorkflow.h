#ifndef COMMUNICATIONSWORKFLOW_H
#define COMMUNICATIONSWORKFLOW_H

#include "util/Util.h"

#include <QObject>
#include <qpps/object.h>
#include "qpps/dirwatcher.h"
class CommunicationsWorkflow : public QObject
{
    Q_OBJECT

    Q_PROPERTY(CommunicationsWorkflow::Page currentPage READ currentPage WRITE setCurrentPage NOTIFY currentPageChanged)
    Q_PROPERTY(CommunicationsWorkflow::Overlay currentOverlay READ currentOverlay WRITE setCurrentOverlay NOTIFY currentOverlayChanged)
    Q_PROPERTY(bool sheetMenuExtended READ sheetMenuExtended WRITE setSheetMenuExtended NOTIFY sheetMenuExtendedChanged)
    Q_PROPERTY(QString enteredNumber READ enteredNumber WRITE setEnteredNumber NOTIFY enteredNumberChanged)
    Q_ENUMS(Page)
    Q_ENUMS(Overlay)

public:
    enum Page {
        GridPage,
        BlueToothPage,
        SmartWatchPage,
        SmartGlassPage,
        DialPadPage,
        ContactSearchPage,
        BtWifiSettings
    };

    enum Overlay {
        NoOverlay,
        CallOverlay
    };

    explicit CommunicationsWorkflow(QObject *parent = 0);
    PROPERTY_WITH_NOTIFY(CommunicationsWorkflow::Page, currentPage, setCurrentPage, currentPageChanged)
    PROPERTY_WITH_NOTIFY(CommunicationsWorkflow::Overlay, currentOverlay, setCurrentOverlay, currentOverlayChanged)
    PROPERTY_WITH_NOTIFY(bool, sheetMenuExtended, setSheetMenuExtended, sheetMenuExtendedChanged)
    PROPERTY_WITH_NOTIFY(QString, enteredNumber, setEnteredNumber, enteredNumberChanged)

public Q_SLOTS:
    void smartGlassOpertion();
    void enterGridPage();
    void enterDialPadPage();
    void enterContactSearchPage();
    void enterCallPage();
    void leaveCallPage();
    void enterSmartGridpage();
    void enterCarPlayPage();
    void enterMirrorLinkPage();
    void enterSmartWatchPage();
    void enterSmartGlassPage();
    void enterBlueToothPage();
    void leaveSmartGridpage();
    void leaveCarPlayPage();
    void leaveMirrorLinkPage();
    void leaveSmartWatchPage();
    void leaveSmartGlassPage();
    void enterBtWifiSettingPage();
    void leaveBtWifiSettingPage();

Q_SIGNALS:
    void onEnterGridPage();
    void onEnterTextMessagesPage();
    void onEnterEmailMessagesPage();
    void onEnterAddressBookPage();
    void onEnterDialPadPage();
    void onEnterContactSearchPage();
    void onEnterCallPage();
    void onLeaveCallPage();
    void onEnterSmartGridpage();
    void onEnterCarPlayPage();
    void onEnterMirrorLinkPage();
    void onEnterSmartWatchPage();
    void onEnterSmartGlassPage();
    void onEnterBlueToothPage();
    void onLeaveSmartGridpage();
    void onLeaveCarPlayPage();
    void onLeaveMirrorLinkPage();
    void onLeaveSmartWatchPage();
    void onLeaveSmartGlassPage();
    void onEnterBtWifiSettingPage();
    void onLeaveBtWifiSettingPage();

private:
    void initStateMachine();
    //int m_smartGlassState;
     QPps::Object *m_ppsStatusObject;
};

#endif
