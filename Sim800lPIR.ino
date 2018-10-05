// Initialization
//PIR
int ledPin = 13;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

//SIM800L
#include <Sim800l.h>
#include <SoftwareSerial.h> //is necesary for the library!! 
Sim800l Sim800l;  //to declare the library
char* text;
char* number;
bool error; //to catch the response of sendSms

//VOID SETUP

void setup() {
// PIR SECTION
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  Serial.begin(9600);

}

//VOID LOOP

void loop(){
//PIR SECTION

  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    // SIM800L SECTION
 
  Sim800l.begin(); // initializate the library. 
  text="Hey Boss are you back home ?I sense motion.";  //text for the message. 
  digitalWrite(ledPin, HIGH);  // turn LED ON
  number="0721934493"; //phone number.
  error=Sim800l.sendSms(number,text);  //Sim800l.sendSms("0721934493","the text go here")

 
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
  
 
}
