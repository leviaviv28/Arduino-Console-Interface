#ifndef ConsoleGraphics_H
#define ConsoleGraphics_H

#include <Wire.h>

#define byte uint8_t
#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

#define CLEAR       0
#define BLACK       1
#define NAVY        2
#define DARKGREEN   3
#define DARKCYAN    4
#define MAROON      5
#define PURPLE      6
#define OLIVE       7
#define LIGHTGREY   8
#define DARKGREY    9
#define BLUE        10
#define GREEN       11
#define CYAN        12
#define RED         13
#define MAGENTA     14
#define YELLOW      15
#define WHITE       16
#define ORANGE      17
#define GREENYELLOW 18
#define PINK        19

class ConsoleGraphics{
    int slaveID;
    
  public:
    int graphicsBufferSize = 0;  
    byte graphicsBuffer[32];
    ConsoleGraphics(int slaveID);
    void pushInt(int convInt);
    void flushBuffer();
    void drawFastVLine(int x, int y, int length, byte color);
    void drawFastHLine(int x, int y, int length, byte color);
    void addRect(int x, int y, int w, int h, byte color);
    void fillRect(int x, int y, int w, int h, byte color);
    void addCircle(int x, int y, int r, byte color);
    void fillCircle(int x, int y, int r, byte color);
    void addTriangle(int x0, int y0, int x1, int y1, int x2, int y2, byte color);
    void fillScreen(byte color);
    void drawPixel(int x, int y, byte color);
    void storeSprite(byte bitmap[25], byte spriteIndex);
    void drawSprite(byte spriteIndex, int x, int y, byte scaler);
    void drawText(int x, int y, byte size, byte color, byte text[25]);
};

#endif