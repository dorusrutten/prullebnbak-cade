#include <Arduino.h>
#include <Audio.h>
#include <SD.h>
#include <FS.h>
#include <SPI.h>
#include <stdio.h>


// SD Card pins
#define SD_CS 5
#define SD_SCK 18
#define SD_MISO 19
#define SD_MOSI 23

// I2S pins
#define I2S_BCLK 27
#define I2S_LRC 26
#define I2S_DOUT 25
#define SDFATFS_USED

//audio
Audio audio;

void setup2()
{
        Serial.begin(9600);
        // wifi();
        while (!Serial)
        {
                Serial.println("SD CARD: INITIALIZING...");
                delay(1000);
        }
        SPI.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);
        if (!SD.begin(SD_CS))// chacks of de sd kaart er in zit
        {
                while (1 > 0)
                {
                        Serial.println("SD CARD: INITIALIZATION FAILED ");// kaart zit niet goed
                        delay(1000);
                }
        }
        else
        {
                Serial.println("SD CARD MOUNTED");// kaart zit goed
        }
        audio.connecttoFS(SD, "pauw2.mp3");        
        audio.setVolume(7); // 0...21
        audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);

}

// void audio_info(const char *info){
// Serial.print("info        "); Serial.println(info);
// }
// bool last  = false;

void loop2()
{
        int sensorPin = 4;
        int sensorValue;
        sensorValue = digitalRead(sensorPin);
        
        if(sensorValue == HIGH){
        audio.loop();
        Serial.println("playing pauw2");
        }
        else{
        Serial.println("LOW");
        }
}