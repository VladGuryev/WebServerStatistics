TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    tests.cpp \
    main.cpp \
    stats.cpp

HEADERS += \
    profile.h \
    test_runner.h \
    stats.h \
    http_request.h
