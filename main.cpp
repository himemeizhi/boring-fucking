#include <QtGui/QGuiApplication>
#include <QQmlContext>
#include "qtquick2applicationviewer.h"
#include"trie.h"

int main(int argc, char *argv[])
{
    Trie trie;
    trie.init();

    QGuiApplication app(argc, argv);
    QtQuick2ApplicationViewer viewer;
    viewer.rootContext()->setContextProperty("trie",&trie);
    viewer.setMainQmlFile(QStringLiteral("qml/untitled/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
