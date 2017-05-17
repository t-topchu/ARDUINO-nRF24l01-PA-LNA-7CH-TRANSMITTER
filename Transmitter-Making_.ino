#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(7,8);
int msg[10];
int pot1=A0;
int pot2=A1;
int X_pin=A2;
int Y_pin=A3;
int joyButton=2;
int button1=3;
int button2=4;
int button3=5;

const uint64_t pipe = 0xDEDEDEDEE7LL;

void setup(void){
 radio.begin();
 radio.setChannel(108);
 radio.setPALevel(RF24_PA_MAX);
 radio.setDataRate(RF24_250KBPS);
 radio.openWritingPipe(pipe);
 Serial.begin(9600);
 pinMode(button1,INPUT);
 pinMode(button2,INPUT);
 pinMode(button3,INPUT);
 pinMode(joyButton,INPUT);
 pinMode(pot1,INPUT);
 pinMode(pot2,INPUT);
}

void loop(void){
 int value0=digitalRead(joyButton);
 msg[0]=value0;
 int value1=digitalRead(button1);
 msg[1]=value1;
 int value2=digitalRead(button2);
 msg[2]=value2;
 int value3=digitalRead(button3);
 msg[3]=value3;
 int value4=analogRead(pot1);
 msg[4]=value4;
 int value5=analogRead(pot2);
 msg[5]=value5;
 int value6=analogRead(X_pin);
 msg[6]=value6;
 int value7=analogRead(Y_pin);
 msg[7]=value7;
 radio.write(msg,sizeof(msg));
}
