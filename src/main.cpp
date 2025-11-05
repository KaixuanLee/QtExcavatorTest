#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "src/RobotController.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QCoreApplication::setOrganizationName("ExampleOrg");
    QCoreApplication::setApplicationName("QtExcavator");

    qmlRegisterType<RobotController>("App", 1, 0, "RobotController");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("QtExcavator/qml/Main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                         if (!obj && url == objUrl)
                             QCoreApplication::exit(-1);
                     }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
