
#include "Print.h"
#include "Builder.h"

#define PATH "C:\\Users\\andrey\\CLionProjects\\test\\out\\test2.txt"

int main() {
    Print *printer = Builder().addConsolePrinter()->addFilePrinter((char *) PATH)->build();
    printer->printResult((char *) "may))");
    delete printer;
    return 0;
}