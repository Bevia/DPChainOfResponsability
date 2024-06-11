#ifndef LASERPRINTERHANDLER_H
#define LASERPRINTERHANDLER_H

#include "PrinterHandler.h"

class LaserPrinterHandler : public PrinterHandler {
protected:
    bool handle(const std::string& request) override {
        if (request == "Laser") {
            std::cout << "LaserPrinterHandler is handling the request." << std::endl;
            return true;
        }
        return false;
    }
};

#endif // LASERPRINTERHANDLER_H
