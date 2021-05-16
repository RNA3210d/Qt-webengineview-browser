import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import Qt.labs.animation 1.0

Item {
    Slider{
        id: sldr
        x: 8
        y: 0
        antialiasing: true
        wheelEnabled: true
    Layout.fillWidth: true
    from: 0
    to: 100
    stepSize: 2
    value: 0
    }

    BusyIndicator {
        id: busyIndicator
        x: 200
        y: 8
    }

    Switch {
        id: switch1
        x: 326
        y: 23
        text: qsTr("Switch")
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
