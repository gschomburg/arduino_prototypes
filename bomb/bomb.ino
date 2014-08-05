/*
"Pipe bomb here"
*/

 //#include "pitches.h"

int motionSwitch = 3;
int yellowButton = 4;
int redBlinker = 9;

int speakerPin = 8;
int beepNote = 2349;

void setup() {
  // initialize serial communication at 9600 bits per second:
  //Serial.begin(9600);
  
  pinMode(motionSwitch, INPUT_PULLUP);
  pinMode(yellowButton, INPUT_PULLUP);
  pinMode(redBlinker, OUTPUT);
}

void loop() {
  //Serial.println('loop');
  
  if(digitalRead(motionSwitch)==LOW){
    startSequence();
  }
  if(digitalRead(yellowButton)==LOW){
    startSequence();
  }
}

void startSequence(){
  
  int noteDuration = 1000/6; //eigth note
  int pauseBetweenNotes = 1000*0.4;
  
  for (int beeps = 0; beeps < 40; beeps++) {
   
    beep(beepNote, noteDuration, pauseBetweenNotes);
    
    //make the beeps shorter and faster
    if(pauseBetweenNotes>40){
      pauseBetweenNotes *= 0.93;
    }
    if(noteDuration>30){
      noteDuration *= .93;
    }
    //Serial.println(pauseBetweenNotes);
  }
  noTone(speakerPin);
}

void beep(int note, int duration, int delayDuration){
  digitalWrite(redBlinker, HIGH);
  tone(speakerPin, note, duration);
  delay(duration);
  digitalWrite(redBlinker, LOW);
  delay(delayDuration);
  
}



