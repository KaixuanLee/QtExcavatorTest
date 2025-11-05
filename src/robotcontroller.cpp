#include "RobotController.h"
#include <QTimer>

RobotController::RobotController(QObject* parent)
    : QObject(parent)
{
}

void RobotController::setJoint1(double v) {
    if (qFuzzyCompare(m_joint1 + 1, v + 1)) return;
    m_joint1 = v;
    emit joint1Changed();
    m_status = QString("Joint1: %1°").arg(m_joint1);
    emit statusChanged();
}

void RobotController::setJoint2(double v) {
    if (qFuzzyCompare(m_joint2 + 1, v + 1)) return;
    m_joint2 = v;
    emit joint2Changed();
    m_status = QString("Joint2: %1°").arg(m_joint2);
    emit statusChanged();
}

void RobotController::setJoint3(double v) {
    if (qFuzzyCompare(m_joint3 + 1, v + 1)) return;
    m_joint3 = v;
    emit joint3Changed();
    m_status = QString("Joint3: %1°").arg(m_joint3);
    emit statusChanged();
}

void RobotController::setClawOpen(bool open) {
    if (m_clawOpen == open) return;
    m_clawOpen = open;
    emit clawOpenChanged();
    m_status = m_clawOpen ? "Bucket: Open" : "Bucket: Closed";
    emit statusChanged();
}

void RobotController::presetHome() {
    // animate or set directly: simple direct set
    setJoint1(10);
    setJoint2(20);
    setJoint3(0);
    setClawOpen(false);
    m_status = "Preset: Home";
    emit statusChanged();
}

void RobotController::presetDig() {
    setJoint1(60);
    setJoint2(25);
    setJoint3(30);
    setClawOpen(false);
    m_status = "Preset: Dig";
    emit statusChanged();
}

void RobotController::presetDump() {
    setJoint1(20);
    setJoint2(-10);
    setJoint3(-20);
    setClawOpen(true);
    m_status = "Preset: Dump";
    emit statusChanged();
}
