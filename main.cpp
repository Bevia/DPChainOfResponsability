#include <iostream>
#include "InkjetPrinterHandler.h"
#include "LaserPrinterHandler.h"
#include "DotMatrixPrinterHandler.h"

//to run this code:
/*
step1: g++ -std=c++11 Main.cpp -o PrinterChain
step2: ./PrinterChain
*/

/*
Explanation

    PrinterHandler: An abstract base class with a method to set the next handler in the chain (setNext) and a method 
    to handle the request (handleRequest). The handle method is pure virtual and must be implemented by concrete handlers.

    InkjetPrinterHandler, LaserPrinterHandler, DotMatrixPrinterHandler: Concrete handlers that inherit from PrinterHandler 
    and implement the handle method. Each handler checks if it can process the request; if not, it passes the request to 
    the next handler in the chain.

    Main.cpp: Sets up the chain of responsibility by linking the handlers. It then tests the chain with different requests 
    to demonstrate how the pattern works.

This design allows you to easily extend the chain by adding new handlers without modifying existing ones, 
following the Open/Closed Principle.

This output confirms that the Chain of Responsibility pattern is working correctly, with each handler processing 
the appropriate request or passing it along the chain until it finds a handler or reaches the end.
*/


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
