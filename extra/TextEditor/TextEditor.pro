
QT       += core gui widgets
greaterThan(QT_MAJOR_VERSION, 5) {
    QT += core5compat
}

CONFIG += c++17
TARGET = ore
TEMPLATE = app

DESTDIR = $$PWD/_bin

unix:QMAKE_CXXFLAGS += -Wall -Wextra -Werror=return-type -Werror=trigraphs -Wno-switch -Wno-reorder

INCLUDEPATH += $$PWD/src
INCLUDEPATH += $$PWD/src/texteditor
INCLUDEPATH += ../../src

linux:LIBS += -lncursesw
macx:LIBS += -lncurses

SOURCES += \
	../../src/common/joinpath.cpp \
	../../src/common/misc.cpp \
	../../src/texteditor/AbstractCharacterBasedApplication.cpp \
	../../src/texteditor/TextEditorTheme.cpp \
	../../src/texteditor/TextEditorView.cpp \
	../../src/texteditor/TextEditorWidget.cpp \
	../../src/texteditor/UnicodeWidth.cpp \
	../../src/texteditor/unicode.cpp \
	src/MainWindow.cpp \
	src/MySettings.cpp \
	src/main.cpp\
	src/cmain.cpp

HEADERS  += \
	../../src/common/joinpath.h \
	../../src/common/misc.h \
	../../src/texteditor/AbstractCharacterBasedApplication.h \
	../../src/texteditor/TextEditorTheme.h \
	../../src/texteditor/TextEditorView.h \
	../../src/texteditor/TextEditorWidget.h \
	../../src/texteditor/UnicodeWidth.h \
	../../src/texteditor/unicode.h \
	src/MainWindow.h \
	src/MySettings.h \
	src/cmain.h

FORMS    += \
	src/MainWindow.ui

