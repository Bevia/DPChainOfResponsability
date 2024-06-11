#include <iostream>
#include "InkjetPrinterHandler.h"
#include "LaserPrinterHandler.h"
#include "DotMatrixPrinterHandler.h"

int main() {
    auto inkjetHandler = std::make_shared<InkjetPrinterHandler>();
    auto laserHandler = std::make_shared<LaserPrinterHandler>();
    auto dotMatrixHandler = std::make_shared<DotMatrixPrinterHandler>();

    // Setting up the chain
    inkjetHandler->setNext(laserHandler);
    laserHandler->setNext(dotMatrixHandler);

    // Test the chain with different requests
    std::cout << "Requesting Inkjet printer..." << std::endl;
    inkjetHandler->handleRequest("Inkjet");

    std::cout << "\nRequesting Laser printer..." << std::endl;
    inkjetHandler->handleRequest("Laser");

    std::cout << "\nRequesting DotMatrix printer..." << std::endl;
    inkjetHandler->handleRequest("DotMatrix");

    std::cout << "\nRequesting an unsupported printer..." << std::endl;
    inkjetHandler->handleRequest("3D");

    return 0;
}
