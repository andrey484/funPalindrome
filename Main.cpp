
#include "Print.h"
#include "Builder.h"

int main() {

    Print *printer = Builder().addConsolePrinter()->
            addFilePrinter((char *) "C:\\Users\\andrey\\CLionProjects\\test\\out\\test2.txt")->build();
    printer->printResult((char *) "may))");
    delete printer;
    return 0;
}