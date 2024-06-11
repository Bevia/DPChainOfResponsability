#ifndef INKJETPRINTERHANDLER_H
#define INKJETPRINTERHANDLER_H

#include "PrinterHandler.h"

class InkjetPrinterHandler : public PrinterHandler {
protected:
    bool handle(const std::string& request) override {
        if (request == "Inkjet") {
            std::cout << "InkjetPrinterHandler is handling the request." << std::endl;
            return true;
        }
        return false;
    }
};

#endif // INKJETPRINTERHANDLER_H
