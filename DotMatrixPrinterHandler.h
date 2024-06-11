#ifndef DOTMATRIXPRINTERHANDLER_H
#define DOTMATRIXPRINTERHANDLER_H

#include "PrinterHandler.h"

class DotMatrixPrinterHandler : public PrinterHandler {
protected:
    bool handle(const std::string& request) override {
        if (request == "DotMatrix") {
            std::cout << "DotMatrixPrinterHandler is handling the request." << std::endl;
            return true;
        }
        return false;
    }
};

#endif // DOTMATRIXPRINTERHANDLER_H
