/*
  State change detection (edge detection)

  Often, you don't need to know the state of a digital input all the time, but
  you just need to know when the input changes from one state to another.
  For example, you want to know when a button goes from OFF to ON. This is called
  state change detection, or edge detection.

  This example shows how to detect when a button or button changes from off to on
  and on to off.

  The circuit:
  - pushbutton attached to pin 2 from +5V
  - 10 kilohm resistor attached to pin 2 from ground
  - LED attached from pin 13 to ground through 220 ohm resistor (or use the
    built-in LED on most Arduino boards)

  created  27 Sep 2005
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/StateChangeDetection
*/

#include <Stepper.h>

// this constant won't change:
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to
const int ledPin2 = 12; 
const int ledPin3 = 11; 

int speakerPin = 6;

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

// Define number of steps per rotation:
int stepsPerRevolution = 1500;
// Create stepper object called 'myStepper', note the pin order:
Stepper myStepper = Stepper(stepsPerRevolution, 7, 9, 8, 10);

int musicNumbers = 0;

void setup() {

  // Set the speed to 5 rpm:
  myStepper.setSpeed(15);
  
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(speakerPin, OUTPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  // initialize serial communication:
  Serial.begin(9600);

//      // Step one revolution in one direction:
//    Serial.println("clockwise");
//    myStepper.step(stepsPerRevolution);
//    delay(500);
//    // Step one revolution in the other direction:
//    Serial.println("counterclockwise");
//    myStepper.step(-stepsPerRevolution);
}


void loop() {
  
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);

      playList();
//      musicNumbers++;
//      motorSpin(musicNumbers);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;


  // turns on the LED every four button pushes by checking the modulo of the
  // button push counter. the modulo function gives you the remainder of the
  // division of two numbers:
  if (buttonPushCounter % 4 == 1) {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
  } else if (buttonPushCounter % 4 == 2){
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin3, HIGH);
  }
   else if (buttonPushCounter % 4 == 3){
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, HIGH);
  } else {
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, HIGH); 
  }
}



/*

  Melody

  Plays a melody

  circuit:

  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010

  modified 30 Aug 2011

  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cchttps://www.arduino.cc/en/Tutorial/Tone

*/

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

// change this to make the song slower or faster
int tempo = 114;

// change this to whichever pin you want to use
int buzzer = 11;

// notes in the melody:
int melody[] = {

  // Never Gonna Give You Up - Rick Astley
  // Score available at https://musescore.com/chlorondria_5/never-gonna-give-you-up_alto-sax
  // Arranged by Chlorondria

//  NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,4, //1
//  NOTE_E5,-4, NOTE_FS5,-4, NOTE_A5,16, NOTE_G5,16, NOTE_FS5,8,
//  NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,2,
//  NOTE_A4,16, NOTE_A4,16, NOTE_B4,16, NOTE_D5,8, NOTE_D5,16,
//  NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,4, //repeat from 1
//  NOTE_E5,-4, NOTE_FS5,-4, NOTE_A5,16, NOTE_G5,16, NOTE_FS5,8,
//  NOTE_D5,-4, NOTE_E5,-4, NOTE_A4,2,
//  NOTE_A4,16, NOTE_A4,16, NOTE_B4,16, NOTE_D5,8, NOTE_D5,16,
//  REST,4, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_D5,8, NOTE_E5,8, NOTE_CS5,-8,
//  NOTE_B4,16, NOTE_A4,2, REST,4, 
//
//  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,4, NOTE_A4,8, //7
//  NOTE_A5,8, REST,8, NOTE_A5,8, NOTE_E5,-4, REST,4, 
//  NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_D5,8, NOTE_E5,8, REST,8,
//  REST,8, NOTE_CS5,8, NOTE_B4,8, NOTE_A4,-4, REST,4,
//  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_A4,4,
//  NOTE_E5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,4, REST,4,
//   
//  NOTE_D5,2, NOTE_E5,8, NOTE_FS5,8, NOTE_D5,8, //13
//  NOTE_E5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,4, NOTE_A4,4,
//  REST,2, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8,
//  REST,8, NOTE_E5,8, NOTE_FS5,8, 
  NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,

  NOTE_E5,-8, NOTE_E5,-8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,-8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16, //18
  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,8, NOTE_A4,8, NOTE_A4,8, 
  NOTE_E5,4, NOTE_D5,2, 
//NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//  NOTE_A5,4, NOTE_CS5,8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//
//  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8,  //23
//  NOTE_E5,4, NOTE_D5,2, REST,4,
//  REST,8, NOTE_B4,8, NOTE_D5,8, NOTE_B4,8, NOTE_D5,8, NOTE_E5,4, REST,8,
//  REST,8, NOTE_CS5,8, NOTE_B4,8, NOTE_A4,-4, REST,4,
//  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_A4,4,
//  REST,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8, NOTE_D5,8,
//  
//  REST,8, NOTE_A4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, //29
//  REST,8, NOTE_CS5,8, NOTE_B4,8, NOTE_A4,-4, REST,4,
//  NOTE_B4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, NOTE_A4,4, REST,8,
//  REST,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,4, NOTE_E5,-4, 
//  NOTE_D5,2, NOTE_D5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,4, 
//  NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8, NOTE_A4,8, NOTE_A4,4,
//
//  REST,-4, NOTE_A4,8, NOTE_B4,8, NOTE_CS5,8, NOTE_D5,8, NOTE_B4,8, //35
//  REST,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//  NOTE_FS5,-8, NOTE_FS5,-8, NOTE_E5,-4, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//  NOTE_E5,-8, NOTE_E5,-8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8, 
//  
//  NOTE_A5,4, NOTE_CS5,8, NOTE_D5,-8, NOTE_CS5,16, NOTE_B4,8, NOTE_A4,16, NOTE_B4,16, NOTE_D5,16, NOTE_B4,16,
//  NOTE_D5,4, NOTE_E5,8, NOTE_CS5,-8, NOTE_B4,16, NOTE_A4,4, NOTE_A4,8, 
//
//  NOTE_E5,4, NOTE_D5,2, REST,4
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

int melody1[] = {

  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int melody2[] = {
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {

  4, 8, 8, 4, 4, 4, 4, 4
};

int noteDurations2[] = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};

//Mario main theme melody
int melody3[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int noteDurations3[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};

void playMusic() {

//  // iterate over the notes of the melody:
//
//  for (int thisNote = 0; thisNote < 8; thisNote++) {
//    Serial.println("clockwise");
//    myStepper.step(stepsPerRevolution/8);
//
//    // to calculate the note duration, take one second divided by the note type.
//
//    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
//
//    int noteDuration = 1000 / noteDurations[thisNote];
//
//    tone(speakerPin, melody[thisNote], noteDuration);
//
//    // to distinguish the notes, set a minimum time between them.
//
//    // the note's duration + 30% seems to work well:
//
//    int pauseBetweenNotes = noteDuration * 1.30;
//
//    delay(pauseBetweenNotes);
////    Serial.println("notenum: ");
////    Serial.println(thisNote);
//
//    noTone(speakerPin);
//
//  }
  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    myStepper.step(stepsPerRevolution/notes*1.35);
    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(speakerPin, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}

void playMusic2() {

  // iterate over the notes of the melody:

  for (int thisNote = 0; thisNote < 26; thisNote++) {
    Serial.println("clockwise");
    myStepper.step(stepsPerRevolution/19.7);

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / noteDurations2[thisNote];

    tone(speakerPin, melody2[thisNote], noteDurations2);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDurations2;

    delay(pauseBetweenNotes);
//    Serial.println("notenum: ");
//    Serial.println(thisNote);

    noTone(speakerPin);

  }
}

void playMusic3() {

  // iterate over the notes of the melody:

  for (int thisNote = 0; thisNote < 78; thisNote++) {

    myStepper.step(stepsPerRevolution/55);
    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 800 / noteDurations3[thisNote];

    tone(speakerPin, melody3[thisNote], noteDurations3);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDurations3;

    delay(pauseBetweenNotes);
//    Serial.println("notenum: ");
//    Serial.println(thisNote);

    noTone(speakerPin);

    Serial.println("clockwise");

  }
}

void playList(){
  if(buttonPushCounter % 4 == 1){
    playMusic();  
  }
  if(buttonPushCounter % 4 == 2){
    playMusic2();
  }
  if(buttonPushCounter % 4 == 3){
    playMusic3();  
  }
}

//void motorSpin(int musicNumber){
//  if(musicNumber % 4 == 1){
//    myStepper.setSpeed(10);
//    Serial.println("clockwise");
//    myStepper.step(stepsPerRevolution);
//  }
//  if(musicNumber % 4 == 2){
//    myStepper.setSpeed(10);
//    Serial.println("counter clockwise");
//    myStepper.step(-stepsPerRevolution);
//  }
//  if(musicNumber % 4 == 3){
//    myStepper.setSpeed(5);
//    Serial.println("counter clockwise");
//    myStepper.step(-stepsPerRevolution);
//    Serial.println("clockwise");
//    myStepper.step(stepsPerRevolution);
//  }
//}







/* Example sketch to control a 28BYJ-48 stepper motor with ULN2003 driver board and Arduino UNO. More info: https://www.makerguides.com */

// Include the Arduino Stepper.h library:
//#include <Stepper.h>

// Define number of steps per rotation:
//const int stepsPerRevolution = 2048;

// Wiring:
// Pin 8 to IN1 on the ULN2003 driver
// Pin 9 to IN2 on the ULN2003 driver
// Pin 10 to IN3 on the ULN2003 driver
// Pin 11 to IN4 on the ULN2003 driver

// Create stepper object called 'myStepper', note the pin order:
//Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

//void setup() {
//  // Set the speed to 5 rpm:
//  myStepper.setSpeed(5);
//  
//  // Begin Serial communication at a baud rate of 9600:
//  Serial.begin(9600);
//}

//void loop() {
//  // Step one revolution in one direction:
//  Serial.println("clockwise");
//  myStepper.step(stepsPerRevolution);
//  delay(500);
//  
//  // Step one revolution in the other direction:
//  Serial.println("counterclockwise");
//  myStepper.step(-stepsPerRevolution);
//  delay(500);
//}
