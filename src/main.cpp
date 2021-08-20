/* 
Simple test program to determine whether ESP32 DMA is enabled
for the TFT_eSPI library

PlatformIO using Arduino framework
*/

#include <Arduino.h>

#include "TFT_eSPI.h"

TFT_eSPI tft = TFT_eSPI();

void setup() {
    #ifdef ESP32_DMA
    log_d("ESP32 DMA enabled");
    #else
    log_d("ESP32 DMA not enabled");
    #endif

    tft.init();

    int startTime = micros();

    tft.fillScreen(TFT_RED);
    tft.fillScreen(TFT_GREEN);
    tft.fillScreen(TFT_BLUE);

    int drawTime = micros() - startTime;

    Serial.begin(115200);
    Serial.println("Hello from Arduino!");
    Serial.print("Draw time was: ");
    Serial.print(drawTime);
    Serial.println(" microseconds.");
}

void loop() {
    delay(1);
}