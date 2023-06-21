#include <Arduino.h>
#include <Audio.h>
#include <SD.h>
#include <FS.h>
#include <SPI.h>
#include <string>
#include <stdio.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

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

// sensor
#define sensorPin 17
int sensorValue;

// wifi
const char *ssid = "iPhone van Dorus";
const char *password = "waffelmaker";
#define SSID YOUR_WIFI_SSID
#define PASSPHRASE YOUR_WIFI_PASSPHRASE
int loopcount = 0;

//audio
Audio audio;

//allows us to use wifi if needed
void wifi()
{
        WiFi.mode(WIFI_STA);
        WiFi.begin(ssid, password);
        Serial.println("\nConnecting");
        while (WiFi.status() != WL_CONNECTED)
        {
                Serial.print(".");
                delay(100);
        }

        Serial.println("\nConnected to the WiFi network");
        Serial.print("Local ESP32 IP: ");
        Serial.println(WiFi.localIP());
        Serial.println("");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
        Serial.println("First set of readings will appear after 10 seconds");
}


void setup()
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
}

// void audio_info(const char *info){
// Serial.print("info        "); Serial.println(info);
// }
// bool last  = false;

void loop()
{
        sensorValue = digitalRead(sensorPin);// read de pin en maakt er een value van

        
        if (sensorValue == HIGH)// als de beweginssensor aan staat
        {
        loopcount++;// telt het aantal loops
        Serial.println("high");// sensor staat aan
                
                switch (loopcount)// verschillende geluiden per loop
                {

                case (1)://loopcount = 1
                {
                        Serial.println("playing peecock sound 1"); // wecht welke sound hij speeld
                        audio.connecttoFS(SD, "pauw1.mp3");// welk bestand je af wilt spelen
                        audio.setVolume(10); // 0...21
                        audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);// zet geluid pins output
                        audio.loop();// speeld geluid af
                        delay(5000);//5 seconde delay
                }
                break;

                case (2):{
                        Serial.println("playing peecock sound 2");
                        audio.connecttoFS(SD, "pauw2.mp3");
                        audio.setVolume(10); // 0...21
                        audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
                        audio.loop();
                        delay(6000);// 6 seconde wachten
                }break;

                case (3):
                        Serial.println("playing peecock sound 3");
                        audio.connecttoFS(SD, "pauw3.mp3");
                            audio.setVolume(10); // 0...21
                        audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
                        audio.loop();
                        delay(7000);// 7 sedonde wachten
                        break;

                case (4):
                        Serial.println("playing peecock sound 4");
                        audio.connecttoFS(SD, "pauw4.mp3");
                        audio.setVolume(10); // 0...21
                        audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
                        audio.loop();
                        delay(7000);// 7 seconde wachten 
                        break;

                case (5):
                        Serial.println("playing peecock sound 5");
                        audio.connecttoFS(SD, "pauw5.mp3");
                        audio.setVolume(10); // 0...21
                        audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
                        audio.loop();
                        delay(5000);// 5 seconde wachten
                        break;

                case (6):
                        Serial.println("playing peecock sound 6");
                        audio.connecttoFS(SD, "pauw6.mp3");
                        audio.setVolume(10); // 0...21
                        audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
                        audio.loop();
                        delay(8000);// 8 seconde wachten
                        break;

                case (7):
                        loopcount = 0;// resets de loopcount
                        break;
                }
        }
        else
        {
                
                        Serial.println("LOW");//prints low
                
        }
}










































































































































































































































































































































































































































































































































































































































































