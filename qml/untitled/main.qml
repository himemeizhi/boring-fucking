import QtQuick 2.0

Rectangle
{
    width: 360
    height: 120
    TextInput
    {
        id: input
        text: "input here"
        focus: true
        anchors.horizontalCenter: parent.horizontalCenter
        y: 20
    }
    Rectangle
    {
        id: button
        width: 240
        height: 24
        anchors.horizontalCenter: input.horizontalCenter
        anchors.top: input.bottom
        anchors.topMargin: 10
        border.color: "#808080"
        Text
        {
            color: "green"
            text: qsTr("Click here to Go")
            anchors.centerIn: parent
        }
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                output.text="Running"
                if(trie.go(input.text))
                    output.text=trie.get()
                else
                    output.text="invaild input"
            }
        }
    }
    TextInput
    {
        id: output
        text: "output here"
        anchors.horizontalCenter: button.horizontalCenter
        anchors.top: button.bottom
        anchors.topMargin: 10
    }
}
