#ifndef PRINTERHANDLER_H
#define PRINTERHANDLER_H

#include <memory>
#include <iostream>

// Abstract base class for the handler
class PrinterHandler {
public:
    virtual ~PrinterHandler() = default;

    // Method to set the next handler in the chain
    void setNext(std::shared_ptr<PrinterHandler> nextHandler) {
        this->nextHandler = nextHandler;
    }

    // Method to handle the request
    void handleRequest(const std::string& request) {
        if (handle(request)) {
            return;
        } else if (nextHandler) {
            nextHandler->handleRequest(request);
        } else {
            std::cout << "No handler could process the request: " << request << std::endl;
        }
    }

protected:
    virtual bool handle(const std::string& request) = 0;

private:
    std::shared_ptr<PrinterHandler> nextHandler;
};

#endif // PRINTERHANDLER_H
