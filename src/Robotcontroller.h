#pragma once
#include <QObject>

class RobotController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double joint1 READ joint1 WRITE setJoint1 NOTIFY joint1Changed)
    Q_PROPERTY(double joint2 READ joint2 WRITE setJoint2 NOTIFY joint2Changed)
    Q_PROPERTY(double joint3 READ joint3 WRITE setJoint3 NOTIFY joint3Changed)
    Q_PROPERTY(bool clawOpen READ clawOpen WRITE setClawOpen NOTIFY clawOpenChanged)
    Q_PROPERTY(QString status READ status NOTIFY statusChanged)

public:
    explicit RobotController(QObject* parent = nullptr);

    double joint1() const { return m_joint1; }
    double joint2() const { return m_joint2; }
    double joint3() const { return m_joint3; }
    bool clawOpen() const { return m_clawOpen; }
    QString status() const { return m_status; }

public slots:
    void setJoint1(double v);
    void setJoint2(double v);
    void setJoint3(double v);
    void setClawOpen(bool open);

    // Presets
    void presetHome();
    void presetDig();
    void presetDump();

signals:
    void joint1Changed();
    void joint2Changed();
    void joint3Changed();
    void clawOpenChanged();
    void statusChanged();

private:
    double m_joint1 = 0.0; // degrees
    double m_joint2 = 0.0;
    double m_joint3 = 0.0;
    bool m_clawOpen = false;
    QString m_status = "Ready";
};
