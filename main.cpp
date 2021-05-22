#include "mainwindow.h"

#include <QApplication>

#include <QWebEngineSettings>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::FullScreenSupportEnabled,true);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::WebGLEnabled,true);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::ErrorPageEnabled,true);

    w.show();
    return a.exec();


}
