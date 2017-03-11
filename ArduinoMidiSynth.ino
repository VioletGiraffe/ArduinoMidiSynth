#include "PDQ_ST7735_config.h"
#include <PDQ_FastPin.h>
#include <PDQ_ST7735.h>

#include <gfxfont.h>
#include <PDQ_GFX.h>

#include <MIDI.h>

#ifndef _PDQ_ST7735H_
#define TFT_RST 0  // you can also connect this to the Arduino reset, in which case, set this #define pin to 0!
Adafruit_ST7735 tft = Adafruit_ST7735(ST7735_CS_PIN, ST7735_DC_PIN, TFT_RST);
#else
PDQ_ST7735 tft;
#endif

MIDI_CREATE_DEFAULT_INSTANCE();

void handleNoteOn(byte inChannel, byte inNote, byte inVelocity)
{

}

void handleNoteOff(byte inChannel, byte inNote, byte inVelocity)
{

}

void setup()
{
  #define AudioOutPin 3
  
  tft.initR(ST7735_INITR_144GREENTAB); // initialize a ST7735S chip, 1.44" TFT, black tab
  tft.fillScreen(ST7735_BLACK);
  tft.setTextWrap(false);

  pinMode(AudioOutPin, OUTPUT);
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
  MIDI.begin();
}

void loop()
{
  MIDI.read();
}

#define RGB_to_565(R, G, B) static_cast<uint16_t>(((R & 0xF8) << 8) | ((G & 0xFC) << 3) | (B >> 3))
