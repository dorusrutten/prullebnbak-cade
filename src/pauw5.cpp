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