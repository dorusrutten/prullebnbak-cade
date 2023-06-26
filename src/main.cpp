//#include <Arduino.h>
#include <Audio.h>
#include <SD.h>
#include <FS.h>
#include <SPI.h>
#include <stdio.h>
#include "pauw1.h"
#include "pauw2.h"
#include "pauw3.h"
#include "pauw4.h"
#include "pauw5.h"

int loopcount;
void setup()
{
loopcount = 0;
Serial.println("strating");
delay(1000);
}



void loop()
{

loopcount++;
switch (loopcount)
{
case (1):
void setup1();
void loop1();
delay(5000);
break;

case (2):
void setup2();
void loop2();
delay(5000);
break;


case (3):
void setup3();
void loop3();
delay(5000);
break;

case (4):
void setup4();
void loop4();
delay(5000);
break;

case (5):
void setup5();
void loop5();
delay(5000);
break;

case (6):
loopcount = 0;

}



}