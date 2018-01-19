include(app.pri)

TEMPLATE = app
TARGET = qnxcar2

QT += core gui quick sql widgets

DEPENDPATH += $$PWD
INCLUDEPATH += $$PWD
DESTDIR = $$BUILD_ROOT/bin/

lessThan(QT_MAJOR_VERSION, 5): error("Qt 5 required")

# qpps
INCLUDEPATH += $$PWD/../qpps
DEPENDPATH += $$PWD/../qpps
win32: LIBPATH += $$BUILD_ROOT/bin
else: LIBPATH += $$BUILD_ROOT/lib
LIBS += -lqpps

# qtqnxcar2
INCLUDEPATH += $$PWD/../qtqnxcar2/qtqnxcar2
DEPENDPATH += $$PWD/../qtqnxcar2/qtqnxcar2
win32: LIBPATH += $$BUILD_ROOT/bin
else: LIBPATH += $$BUILD_ROOT/lib
LIBS += -lqtqnxcar2

# qtqnxcar2-ui
INCLUDEPATH += $$PWD/../qtqnxcar2-ui/qtqnxcar2-ui
DEPENDPATH += $$PWD/../qtqnxcar2-ui/qtqnxcar2-ui
win32: LIBPATH += $$BUILD_ROOT/bin
else: LIBPATH += $$BUILD_ROOT/lib
LIBS += -lqtqnxcar2-ui

# qplayer
INCLUDEPATH += $$PWD/../qplayer
DEPENDPATH += $$PWD/../qplayer
win32: LIBPATH += $$BUILD_ROOT/bin
else: LIBPATH += $$BUILD_ROOT/lib
LIBS += -lqplayer

# kanzi
INCLUDEPATH += $$PWD/../kanzi
DEPENDPATH += $$PWD/../kanzi
win32: LIBPATH += $$BUILD_ROOT/bin
else: LIBPATH += $$BUILD_ROOT/lib
LIBS += -lkanzi

target.path = $$INSTALL_PREFIX/bin

other_files.files = qml images fonts palettes run-qnxcar2.sh sampledata
other_files.path = $$INSTALL_PREFIX/share/qnxcar2

INSTALLS += target other_files

DEFINES += QT_NO_CAST_FROM_ASCII QT_NO_CAST_TO_ASCII QT_NO_URL_CAST_FROM_STRING

SOURCES += \
	main.cpp \
	AppLauncherServer.cpp \
	Core.cpp \
	ExternalApplication.cpp \
	ExternalWindow.cpp \
	KeyboardProcess.cpp \
	ModuleManager.cpp \
	ProfileSettingsManager.cpp \
	RendererControl.cpp \
	ScreenManager.cpp \
	Status.cpp \
	Util.cpp \
		VoiceInput.cpp

HEADERS += \
	AppLauncherServer.h \
	Core.h \
	ExternalApplication.h \
	ExternalWindow.h \
	KeyboardProcess.h \
	ModuleManager.h \
	ProfileSettingsManager.h \
	RendererControl.h \
	ScreenManager.h \
	Status.h \
	Util.h \
		VoiceInput.h \
	Layout.h

include(modules/modules.pri)
#include(simulator/simulator.pri)
include(applicationmanager/applicationmanager.pri)

OTHER_FILES += \
	palettes/classic.qml \
	palettes/sports.qml \
	palettes/technology.qml

DISTFILES += \
#    tts/tts.pri

