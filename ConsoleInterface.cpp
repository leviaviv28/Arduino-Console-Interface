#include "ConsoleInterface.h"

ConsoleInterface::ConsoleInterface(){
    Wire.begin();
    Wire.setClock(400000);
}

void ConsoleInterface::getInputs(){
    Wire.requestFrom(SLAVE_ID, NUM_BUTTONS);
    for(int i = 0; i < NUM_BUTTONS; i++){
        btnArr[i] = Wire.read();
    }
}
