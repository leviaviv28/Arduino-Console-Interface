#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H

#include "ConsoleGraphics.h"

class ConsoleInterface{
public:
	int NUM_BUTTONS = 6;
    byte btnArr[6] = {0,0,0,0,0,0};
    int SLAVE_ID = 8;
	ConsoleGraphics screen = new ConsoleGraphics(8);
	ConsoleInterface();
	void getInputs();
};

#endif