#ifndef ConsoleGraphics_H
#define ConsoleGraphics_H

#define byte uint8_t
#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

#include <Wire.h>

typedef struct {
  int r;
  int g;
  int b;
}RGBColor;

class ConsoleGraphics{
  private:
    int slaveID;
    
    
  public:
    int graphicsBufferSize = 0;  
    byte graphicsBuffer[32];
    ConsoleGraphics(int slaveID);
    void pushInt(int convInt);
    void sendGraphics();
    void addFastVLine(int x, int y, int length, RGBColor color);
    void addFastHLine(int x, int y, int length, RGBColor color);
    void addRect(int x, int y, int w, int h, RGBColor color);
    void fillRect(int x, int y, int w, int h, RGBColor color);
    void addCircle(int x, int y, int r, RGBColor color);
    void fillCircle(int x, int y, int r, RGBColor color);
    void addTriangle(int x0, int y0, int x1, int y1, int x2, int y2, RGBColor color);
    void addFillScreen(RGBColor color);
};

#endif