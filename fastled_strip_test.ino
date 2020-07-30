// RGB Strip tester
//
// Turns on all led on and off on your strip 1 by 1 in RGBW sequence.
//
// Set your Serial port to 115200 for moonitor which led which color is on
//
// You can set
//  - brightness 0-255
//  - delay for slow down ( set 1000 for 1 sec delay )
//  - start led, where test starts from ( first led always 0 )
//  - stop led, where test is stop
//  - type of your led strip ( uncomment approirate line below in void setup section )
//
// GNU General Public Licence V3.0
//
// Sketch ver 1.1

#include "FastLED.h"

#define DATA_PIN 12     // your data pin
//#define CLOCK_PIN 13  // your clock pin if need

// How many leds in your strip?
const int NUM_LEDS = 288;        //  number of leds on your strip
int BRIGHTNESS = 255;     //  value between 0 and 255
int DELAY = 0;            // 1/1000 sec, so 1000 is 1 sec
int START_LED = 0;        // strip first led address is 0
int STOP_LED  = 287;      // maximum last led address is NUM_LEDS - 1

CRGB leds[NUM_LEDS];
 
void setup() { 
  Serial.begin(115200);
  while (!Serial) { // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("");
  Serial.println("Booting...");
  if ( STOP_LED > NUM_LEDS ) {   STOP_LED =  NUM_LEDS - 1; }
  if ( STOP_LED < START_LED ) { STOP_LED =  START_LED; }
  
    // Uncomment/edit one of the following lines for your leds arrangement.
    // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);    // GRB ordering is typical
     FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);   // GRB ordering is typical
    // FastLED.addLeds<WS2852, DATA_PIN, GRB>(leds, NUM_LEDS);    // GRB ordering is typical
    // FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    // FastLED.addLeds<APA104, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<GW6205, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<GW6205_400, DATA_PIN, RGB>(leds, NUM_LEDS);
 
    // FastLED.addLeds<WS2801, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<SM16716, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<LPD8806, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<P9813, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<APA102, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<DOTSTAR, RGB>(leds, NUM_LEDS);
 
    // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);

    // turn off all led
      for(int i=0; i< NUM_LEDS; i++){
        leds[i] = CRGB(0,0,0);
        FastLED.show();
    }
    FastLED.clear();
    
    Serial.println("Ready. Start looping.");
}
 
void loop() {
//red
    for(int i= START_LED; i<= STOP_LED; i++){
        Serial.print("Red  ");
        Serial.println(i);
        leds[i] = CRGB(BRIGHTNESS, 0, 0);
        FastLED.show();
        delay(DELAY);
        FastLED.clear();
        //leds[i] = CRGB(0,0,0);
        //FastLED.show();
    }

//green
    for(int i=START_LED; i<=STOP_LED; i++){
        Serial.print("Green  ");
        Serial.println(i);
        leds[i] = CRGB(0, BRIGHTNESS, 0);
        FastLED.show();
        delay(DELAY);
        FastLED.clear();
        //leds[i] = CRGB(0,0,0);
        //FastLED.show();
    }

//blue
    for(int i=START_LED; i<=STOP_LED; i++){
        Serial.print("Blue  ");
        Serial.println(i);
        leds[i] = CRGB(0, 0, BRIGHTNESS);
        FastLED.show();
        delay(DELAY);
        FastLED.clear();
        //leds[i] = CRGB(0,0,0);
        //FastLED.show();
    }

//white
    for(int i=START_LED; i<=STOP_LED; i++){
        Serial.print("White ");
        Serial.println(i);
        leds[i] = CRGB(BRIGHTNESS, BRIGHTNESS, BRIGHTNESS);
        FastLED.show();
        delay(DELAY);
        FastLED.clear();
        //leds[i] = CRGB(0,0,0);
        //FastLED.show();
    }
}
