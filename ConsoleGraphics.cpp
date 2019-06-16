#include "ConsoleGraphics.h"


ConsoleGraphics::ConsoleGraphics(int slaveID) : slaveID(slaveID) {}

void ConsoleGraphics::pushInt(int convInt) {
    graphicsBuffer[graphicsBufferSize++] = lowByte(convInt);
    graphicsBuffer[graphicsBufferSize++] = highByte(convInt);
}

void ConsoleGraphics::flushBuffer(){
    Wire.beginTransmission(8);
    Wire.write(graphicsBufferSize);
    for(int i = 0; i < graphicsBufferSize; i++){
        Wire.write(graphicsBuffer[i]);
        
    }
    Wire.endTransmission();
    graphicsBufferSize = 0;
}
    
void ConsoleGraphics::drawFastVLine(int x, int y, int length, byte color){
    graphicsBuffer[graphicsBufferSize++] = 0;
    pushInt(x);
    pushInt(y);
    pushInt(length);
    graphicsBuffer[graphicsBufferSize++] = color;
    flushBuffer();
}
  
void ConsoleGraphics::drawFastHLine(int x, int y, int length, byte color){
    graphicsBuffer[graphicsBufferSize++] = 1;
    pushInt(x);
    pushInt(y);
    pushInt(length);
    graphicsBuffer[graphicsBufferSize++] = color;
    flushBuffer();
}

void ConsoleGraphics::addRect(int x, int y, int w, int h, byte color){
    graphicsBuffer[graphicsBufferSize++] = 2;
    pushInt(x);
    pushInt(y);
    pushInt(w);
    pushInt(h);
    graphicsBuffer[graphicsBufferSize++] = color;
    flushBuffer();
}

void ConsoleGraphics::fillRect(int x, int y, int w, int h, byte color){
    graphicsBuffer[graphicsBufferSize++] = 3;
    pushInt(x);
    pushInt(y);
    pushInt(w);
    pushInt(h);
    graphicsBuffer[graphicsBufferSize++] = color;
    flushBuffer();
}

void ConsoleGraphics::addCircle(int x, int y, int r, byte color){
    graphicsBuffer[graphicsBufferSize++] = 4;
    pushInt(x);
    pushInt(y);
    pushInt(r);
    graphicsBuffer[graphicsBufferSize++] = color;
    flushBuffer();
}

void ConsoleGraphics::fillCircle(int x, int y, int r, byte color){
    graphicsBuffer[graphicsBufferSize++] = 5;
    pushInt(x);
    pushInt(y);
    pushInt(r);
    graphicsBuffer[graphicsBufferSize++] = color;
    flushBuffer();
}

void ConsoleGraphics::addTriangle(int x0, int y0, int x1, int y1, int x2, int y2, byte color){
    graphicsBuffer[graphicsBufferSize++] = 6;
    pushInt(x0);
    pushInt(y0);
    pushInt(x1);
    pushInt(y1);
    pushInt(x2);
    pushInt(y2);
    graphicsBuffer[graphicsBufferSize++] = color;
    flushBuffer();
}

void ConsoleGraphics::fillScreen(byte color){
    graphicsBuffer[graphicsBufferSize++] = 7;
    graphicsBuffer[graphicsBufferSize++] = color;
    flushBuffer();
}

void ConsoleGraphics::drawPixel(int x, int y, byte color){
    graphicsBuffer[graphicsBufferSize++] = 8;
    pushInt(x);
    pushInt(y);
    graphicsBuffer[graphicsBufferSize++] = color;
    flushBuffer();
}

void ConsoleGraphics::storeSprite(byte bitmap[25], byte spriteIndex){
    graphicsBuffer[graphicsBufferSize++] = 9;
    graphicsBuffer[graphicsBufferSize++] = spriteIndex;
    for(int i = 0; i < 25; i++){
        graphicsBuffer[graphicsBufferSize++] = bitmap[i];
    }
    flushBuffer();
}

void ConsoleGraphics::drawSprite(byte spriteIndex, int x, int y, byte scaler){
    graphicsBuffer[graphicsBufferSize++] = 10;
    graphicsBuffer[graphicsBufferSize++] = spriteIndex;
    pushInt(x);
    pushInt(y);
    graphicsBuffer[graphicsBufferSize++] = scaler;
    flushBuffer();
}

void ConsoleGraphics::drawText(int x, int y, byte size, byte color, byte text[25]){
    graphicsBuffer[graphicsBufferSize++] = 11;
    pushInt(x);
    pushInt(y);
    graphicsBuffer[graphicsBufferSize++] = size;
    graphicsBuffer[graphicsBufferSize++] = color;
    for(int i = 0; i < 25; i++){
        graphicsBuffer[graphicsBufferSize++] = text[i];
    }
    flushBuffer();
}