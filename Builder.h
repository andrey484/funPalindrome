//
// Created by andrey on 05.01.2017.
//

#ifndef FUNPALINDROME_BUILDER_H
#define FUNPALINDROME_BUILDER_H

#include "Print.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Builder {
    class Compositor;
private:
    Compositor *compositor;

    class PrintToConsole : public Print {
    public:
        virtual void printResult(char * expr) override {
            std::cout << expr;
        }
    };

    class PrintToFile : public Print {
    public:
        virtual void printResult(char * expr) override {
            outputFile << expr;
        }

        virtual ~PrintToFile() {
            outputFile.close();
        }

        ofstream outputFile;

        PrintToFile(char *filename) {
            outputFile = ofstream(filename, ios_base::out | ios_base::trunc);
            if(!outputFile.is_open())
                cout << "not open";
        }
    };

    class Compositor : public Print {
    private:
        vector<Print *> listOfPrinters;
    public:
        ~Compositor(){
            for(int i=0;i<listOfPrinters.size();i++)
                delete listOfPrinters[i];
        }
        virtual void printResult(char * expr) override{
            for(unsigned int i = 0; i < listOfPrinters.size(); i++)
                listOfPrinters.at(i)->printResult(expr);
        }

        void addPrinter(Print *object) {
            listOfPrinters.push_back(object);
        }
    };

public:
    Builder *addConsolePrinter() {
        compositor->addPrinter(new PrintToConsole);
        return this;
    }

    Builder *addFilePrinter(char *filename) {
        compositor->addPrinter(new PrintToFile(filename));
        return this;
    }

    Print *build(){
        return compositor;
    }

    Builder(){
        compositor = new Compositor;
    }
};


#endif //FUNPALINDROME_BUILDER_H
