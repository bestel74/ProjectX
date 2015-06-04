#include "slateapi.h"
#include "ui_slateapi.h"

#include <iostream>

using std::cout;
using std::endl;

SlateAPI::SlateAPI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SlateAPI)
{
    ui->setupUi(this);

    iskn_SlateManager  = new SlateManager();
    iskn_Device     = &iskn_SlateManager->getDevice();
    iskn_SlateManager->registerListener(this);

    // Connect to the Slate
    if (iskn_SlateManager->connect())
    {
      cout<<"Ask for connection..."<<endl;
    }
    else
    {
      QMessageBox::critical(this, tr("Error"), tr("Slate is not connected. Check your USB connection."));
      cout<<"Could not connect..."<<endl;
      exit(0);
    }
}

SlateAPI::~SlateAPI()
{
    delete ui;
}

void SlateAPI::connectionStatusChanged(bool connected)
{
    if(connected) {
      // Request Slate description
      iskn_SlateManager->request(REQ_DESCRIPTION);

      // Subscribe to events (Status, Pen Status, Function Call and Pen_3D)
      iskn_SlateManager->subscribe(
          AUTO_STATUS |
          AUTO_SOFTWARE_EVENTS |
          AUTO_HARDWARE_EVENTS |
          AUTO_PEN_3D
      );
    }
}

void SlateAPI::processEvent(Event &e, unsigned int timecode)
{
    (void) timecode; //parameter not used

    switch(e.Type)
    {
    case EVT_DESCRIPTION:
        cout <<"Slate connected : "<<e.Description.getDeviceName()<<endl;
        break;

    default:
        break;
    }
}
