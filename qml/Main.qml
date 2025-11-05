import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts

import App 1.0

Window {
    id: root
    width: 1200
    height: 720
    visible: true
    title: "ExcavatorArm"

    // The backend controller instance (created in QML)
    RobotController {
        id: controller
    }

    property bool darkMode: false

    Rectangle {
        anchors.fill: parent
        color: darkMode ? "#222222" : "#faf7f7"

        // Top status
        Text {
            id: statusText
            text: controller.status
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 12
            font.italic: true
            color: darkMode ? "#cccccc" : "#444444"
        }

        RowLayout {
            anchors.fill: parent
            anchors.margins: 20
            spacing: 24

            // Left control column
            ColumnLayout {
                Layout.preferredWidth: 300
                spacing: 16

                RowLayout {
                    spacing: 12
                    Label { text: "Dark mode"; color: darkMode ? "white" : "#333" }
                    Switch {
                        checked: darkMode
                        onCheckedChanged: root.darkMode = checked
                    }
                }

                // Preset buttons
                ColumnLayout {
                    spacing: 8
                    RowLayout {
                        spacing: 8
                        Button { text: "Preset Home"; onClicked: controller.presetHome() }
                        Button { text: "Preset Dig"; onClicked: controller.presetDig() }
                    }
                    RowLayout {
                        spacing: 8
                        Button { text: "Preset Dump"; onClicked: controller.presetDump() }
                        Button { text: "Reset"; onClicked: {
                            controller.setJoint1(0); controller.setJoint2(0); controller.setJoint3(0); controller.setClawOpen(false)
                        } }
                    }
                }

                // Claw toggle
                RowLayout {
                    spacing: 12
                    Label { text: "Bucket"; color: darkMode ? "white" : "#333" }
                    Switch { checked: controller.clawOpen; onCheckedChanged: controller.setClawOpen(checked) }
                }

                // Sliders for joints
                ColumnLayout {
                    spacing: 12

                    RowLayout {
                        spacing: 8
                        Label { text: "Boom (Joint1)"; color: darkMode ? "white" : "#333" ; Layout.alignment: Qt.AlignVCenter }
                        Text { text: Math.round(controller.joint1) ; color: darkMode ? "white" : "#333" }
                    }
                    Slider {
                        from: -30; to: 90
                        value: controller.joint1
                        onMoved: controller.setJoint1(value)
                        live: true
                        Layout.preferredWidth: 260
                    }

                    RowLayout {
                        spacing: 8
                        Label { text: "Stick (Joint2)"; color: darkMode ? "white" : "#333" ; Layout.alignment: Qt.AlignVCenter }
                        Text { text: Math.round(controller.joint2) ; color: darkMode ? "white" : "#333" }
                    }
                    Slider {
                        from: -60; to: 90
                        value: controller.joint2
                        onMoved: controller.setJoint2(value)
                        live: true
                        Layout.preferredWidth: 260
                    }

                    RowLayout {
                        spacing: 8
                        Label { text: "Bucket (Joint3)"; color: darkMode ? "white" : "#333" ; Layout.alignment: Qt.AlignVCenter }
                        Text { text: Math.round(controller.joint3) ; color: darkMode ? "white" : "#333" }
                    }
                    Slider {
                        from: -90; to: 90
                        value: controller.joint3
                        onMoved: controller.setJoint3(value)
                        live: true
                        Layout.preferredWidth: 260
                    }
                }

                // Stretch to top
                Item { Layout.fillHeight: true }
            }

            // Center: Excavator visual area
            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                color: "transparent"

                // Stage
                Item {
                    id: stage
                    anchors.centerIn: parent
                    width: parent.width * 0.6
                    height: parent.height * 0.9

                    // ground
                    Rectangle {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.bottom: parent.bottom
                        height: 8
                        y: parent.height - 20
                        color: darkMode ? "#111111" : "#dddddd"
                    }

                    // base (rotating base optional)
                    Rectangle {
                        id: base
                        width: 120; height: 40
                        x: (parent.width - width)/2
                        y: parent.height - 140
                        radius: 6
                        color: darkMode ? "#2b2b2b" : "#dcdcdc"
                        border.color: darkMode ? "#444" : "#bbb"
                    }

                    // Boom (joint1) - pivot at base.right center
                    Rectangle {
                        id: boom
                        width: 200; height: 18
                        color: darkMode ? "#7a7a7a" : "#cfcfcf"
                        radius: 8
                        x: base.x + base.width - 20
                        y: base.y - height/2 + 6
                        transform: Rotation { origin.x: 20; origin.y: height/2; angle: controller.joint1 }
                        anchors.verticalCenter: undefined
                    }

                    // Joint1 circle
                    Rectangle {
                        width: 36; height: 36
                        radius: 18
                        x: boom.x - 18
                        y: boom.y - 9
                        color: darkMode ? "#3a3a3a" : "#efefef"
                        border.color: darkMode ? "#555" : "#ccc"
                    }

                    // Stick (joint2) - pivot at boom.right
                    Rectangle {
                        id: stick
                        width: 160; height: 14
                        color: darkMode ? "#8b8b8b" : "#e3e3e3"
                        radius: 6
                        x: boom.x + boom.width - 6
                        // y based on boom center
                        y: boom.y + (boom.height - height)/2
                        transform: Rotation {
                            origin.x: 10; origin.y: height/2
                            angle: controller.joint1 + controller.joint2
                        }
                    }

                    // Joint2 circle
                    Rectangle {
                        width: 28; height: 28; radius: 14
                        x: stick.x - 14
                        y: stick.y - 7
                        color: darkMode ? "#3a3a3a" : "#f5f5f5"
                        border.color: darkMode ? "#555" : "#ddd"
                    }

                    // Bucket arm (joint3) - pivot at stick.right
                    Rectangle {
                        id: bucketArm
                        width: 90; height: 12
                        color: darkMode ? "#9aa" : "#eee"
                        radius: 6
                        x: stick.x + stick.width - 6
                        y: stick.y + (stick.height - height)/2
                        transform: Rotation {
                            origin.x: 8; origin.y: height/2
                            angle: controller.joint1 + controller.joint2 + controller.joint3
                        }
                    }

                    // Bucket (simple wedge)
                    Canvas {
                        id: bucketCanvas
                        width: 64; height: 48
                        x: bucketArm.x + bucketArm.width - 10
                        y: bucketArm.y - 18
                        rotation: controller.joint1 + controller.joint2 + controller.joint3
                        transform: Translate { x: 0; y: 0 }
                        onPaint: {
                            var ctx = getContext("2d");
                            ctx.reset();
                            ctx.clearRect(0,0,width,height);
                            ctx.beginPath();
                            // draw bucket shape (triangle)
                            ctx.moveTo(8, 8);
                            ctx.lineTo(56, 24);
                            ctx.lineTo(8, 40);
                            ctx.closePath();
                            ctx.fillStyle = controller.clawOpen ? "#66cc66" : (darkMode ? "#aaaaaa" : "#cccccc");
                            ctx.fill();
                            ctx.strokeStyle = darkMode ? "#666" : "#999";
                            ctx.lineWidth = 2;
                            ctx.stroke();
                        }
                    }

                    // labels
                    Text { text: "Boom (Joint1)"; color: darkMode ? "#ddd" : "#666"; x: 10; y: 10 }
                    Text { text: "Stick (Joint2)"; color: darkMode ? "#ddd" : "#666"; x: 10; y: 30 }
                    Text { text: "Bucket (Joint3)"; color: darkMode ? "#ddd" : "#666"; x: 10; y: 50 }

                } // stage
            } // center rectangle

        } // RowLayout
    }
}
