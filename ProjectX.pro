#-------------------------------------------------
#
# Project created by QtCreator 2015-06-03T11:06:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = ProjectX
TEMPLATE = app


SOURCES += main.cpp\
        slateapi.cpp

HEADERS  += slateapi.h

FORMS    += slateapi.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../API/bin/ -lISKN_API
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../API/bin/ -lISKN_APId
else:unix: LIBS += -L$$PWD/../API/bin/ -lISKN_API

INCLUDEPATH += $$PWD/../API/include
DEPENDPATH += $$PWD/../API/include
