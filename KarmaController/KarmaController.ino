// v1.2
// Karma Controller by William Wnekowicz - Likely Nothing LLC
// This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License. 
// To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/.

#include "DigiKeyboard.h"

int lastReading0 = 0;
int lastReading1 = 0;
int lastReading2 = 0;
int lastReading5 = 0;

void setup() {      
  pinMode(0, INPUT); //button0 
  pinMode(1, INPUT); //button1
  pinMode(2, INPUT); //button2 & button3
  pinMode(5, INPUT); //button4 & button5 & button6
}

void loop() {
  int reading0 = digitalRead(0);
  int reading1 = digitalRead(1);
  int reading2 = analogRead(1);  
  int reading5 = analogRead(0);

  if(reading0 == HIGH && reading0 != lastReading0){
    DigiKeyboard.print("j");
  }

  if(reading1 == HIGH && reading1 != lastReading1){ 
    DigiKeyboard.print("x"); 
  }
  
  if((reading2 >= 1010 && reading2 <= 1024) && !(lastReading2 >= 1010 && lastReading2 <= 1024)){
    DigiKeyboard.print("a"); 
  }
  
  if((reading2 >= 920 && reading2 <= 940) && !(lastReading2 >= 920 && lastReading2 <= 940)){
    DigiKeyboard.print("z"); 
  }
  
  if((reading5 >= 532 && reading5 <= 546) && !(lastReading5 >= 532 && lastReading5 <= 546)){
    DigiKeyboard.print("C");
  }
  
  if((reading5 >= 865 && reading5 <= 885) && !(lastReading5 >= 865 && lastReading5 <= 885)){
    DigiKeyboard.sendKeyStroke(KEY_W,MOD_GUI_LEFT); 
  }
  
  if((reading5 >= 1010 && reading5 <= 1024) && !(lastReading5 >= 1010 && lastReading5 <= 1024)){

    DigiKeyboard.print("k"); 
  }
  
  lastReading0 = reading0; 
  lastReading1 = reading1;
  lastReading2 = reading2;  
  lastReading5 = reading5; 
  
  DigiKeyboard.delay(1);
}
