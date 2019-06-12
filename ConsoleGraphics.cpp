#include "ConsoleGraphics.h"


ConsoleGraphics::ConsoleGraphics(int slaveID) : slaveID(slaveID) {}

void ConsoleGraphics::pushInt(int convInt) {
    graphicsBuffer[graphicsBufferSize++] = lowByte(convInt);
    graphicsBuffer[graphicsBufferSize++] = highByte(convInt);
}

void ConsoleGraphics::sendGraphics(){
    Wire.beginTransmission(8);
    Wire.write(graphicsBufferSize);
    for(int i = 0; i < graphicsBufferSize; i++){
        Wire.write(graphicsBuffer[i]);
        
    }
    Wire.endTransmission();
    graphicsBufferSize = 0;
}
    
void ConsoleGraphics::addFastVLine(int x, int y, int length, RGBColor color){
    graphicsBuffer[graphicsBufferSize++] = 0;
    graphicsBuffer[graphicsBufferSize++] = color.r;
    graphicsBuffer[graphicsBufferSize++] = color.g;
    graphicsBuffer[graphicsBufferSize++] = color.b;
    pushInt(x);
    pushInt(y);
    pushInt(length);
    sendGraphics();
}
  
void ConsoleGraphics::addFastHLine(int x, int y, int length, RGBColor color){
    graphicsBuffer[graphicsBufferSize++] = 1;
    graphicsBuffer[graphicsBufferSize++] = color.r;
    graphicsBuffer[graphicsBufferSize++] = color.g;
    graphicsBuffer[graphicsBufferSize++] = color.b;
    pushInt(x);
    pushInt(y);
    pushInt(length);
    sendGraphics();
}

void ConsoleGraphics::addRect(int x, int y, int w, int h, RGBColor color){
    graphicsBuffer[graphicsBufferSize++] = 2;
    graphicsBuffer[graphicsBufferSize++] = color.r;
    graphicsBuffer[graphicsBufferSize++] = color.g;
    graphicsBuffer[graphicsBufferSize++] = color.b;
    pushInt(x);
    pushInt(y);
    pushInt(w);
    pushInt(h);
    sendGraphics();
}

void ConsoleGraphics::fillRect(int x, int y, int w, int h, RGBColor color){
    graphicsBuffer[graphicsBufferSize++] = 3;
    graphicsBuffer[graphicsBufferSize++] = color.r;
    graphicsBuffer[graphicsBufferSize++] = color.g;
    graphicsBuffer[graphicsBufferSize++] = color.b;
    pushInt(x);
    pushInt(y);
    pushInt(w);
    pushInt(h);
    sendGraphics();
}

void ConsoleGraphics::addCircle(int x, int y, int r, RGBColor color){
    graphicsBuffer[graphicsBufferSize++] = 4;
    graphicsBuffer[graphicsBufferSize++] = color.b;
    graphicsBuffer[graphicsBufferSize++] = color.g;
    graphicsBuffer[graphicsBufferSize++] = color.r;
    pushInt(x);
    pushInt(y);
    pushInt(r);
    sendGraphics();
}

void ConsoleGraphics::fillCircle(int x, int y, int r, RGBColor color){
    graphicsBuffer[graphicsBufferSize++] = 5;
    graphicsBuffer[graphicsBufferSize++] = color.b;
    graphicsBuffer[graphicsBufferSize++] = color.g;
    graphicsBuffer[graphicsBufferSize++] = color.r;
    pushInt(x);
    pushInt(y);
    pushInt(r);
    sendGraphics();
}

void ConsoleGraphics::addTriangle(int x0, int y0, int x1, int y1, int x2, int y2, RGBColor color){
    graphicsBuffer[graphicsBufferSize++] = 6;
    pushInt(x0);
    pushInt(y0);
    pushInt(x1);
    pushInt(y1);
    pushInt(x2);
    pushInt(y2);
    graphicsBuffer[graphicsBufferSize++] = color.b;
    graphicsBuffer[graphicsBufferSize++] = color.g;
    graphicsBuffer[graphicsBufferSize++] = color.r;
    sendGraphics();
}

void ConsoleGraphics::addFillScreen(RGBColor color){
    graphicsBuffer[graphicsBufferSize++] = 7;
    graphicsBuffer[graphicsBufferSize++] = color.r;
    graphicsBuffer[graphicsBufferSize++] = color.g;
    graphicsBuffer[graphicsBufferSize++] = color.b;
    sendGraphics();
}



