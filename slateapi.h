#ifndef SLATEAPI_H
#define SLATEAPI_H

#include <QMainWindow>
#include <QMessageBox>

#include "ISKN_API.h"

using namespace ISKN_API;

namespace Ui {
class SlateAPI;
}

class SlateAPI : public QMainWindow, public Listener
{
    Q_OBJECT

public:
    explicit SlateAPI(QWidget *parent = 0);
    ~SlateAPI();

    void processEvent(Event &e, unsigned int timecode);
    void connectionStatusChanged(bool connected);


    SlateManager *iskn_SlateManager;
    Device      *iskn_Device;

private:
    Ui::SlateAPI *ui;
};

#endif // SLATEAPI_H
