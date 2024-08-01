/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN PA0
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 22 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(100);
  // initialize LED digital pin as an output.

  // pinMode(PA1, INPUT_ANALOG);
  // pinMode(PA2, INPUT_ANALOG);
  // pinMode(PA3, INPUT_ANALOG);
  // pinMode(PA4, INPUT_ANALOG);
}

int brightness = 100;
int red = 100;
int green = 0;
int blue = 0;

void loop()
{
  red = map(analogRead(PA2),        0, 4096, 0, 255);
  blue = map(analogRead(PA3),       0, 4096, 0, 255);
  green = map(analogRead(PA4),      0, 4096, 0, 255);
  brightness = map(analogRead(PA5), 0, 4096, 0, 255);
  pixels.fill(pixels.Color(red, blue, green));
  pixels.setBrightness(brightness);
  pixels.show();   // Send the updated pixel colors to the hardware.
  // // turn the LED on (HIGH is the voltage level)
  // digitalWrite(LED_BUILTIN, HIGH);
  // // wait for a second
  // delay(1000);
  // pixels.fill(pixels.Color(0, 0, 0));
  // pixels.setPixelColor((pixToSet++ % 3), pixels.Color(255, 0, 0));
  // pixels.show();   // Send the updated pixel colors to the hardware.
  // // turn the LED off by making the voltage LOW
  // digitalWrite(LED_BUILTIN, LOW);
  //  // wait for a second
  // delay(1000);
}
