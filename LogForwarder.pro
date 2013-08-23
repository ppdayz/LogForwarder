#-------------------------------------------------
#
# Project created by QtCreator 2013-08-07T16:22:01
#
#-------------------------------------------------

QT       += core network
QT       -= gui

TARGET = LogForwarder
TEMPLATE = app


SOURCES += main.cpp \
    forwardserver.cpp \
    readstdinthread.cpp \
    forwardlink.cpp

HEADERS += \
    forwardserver.h \
    readstdinthread.h \
    forwardlink.h
