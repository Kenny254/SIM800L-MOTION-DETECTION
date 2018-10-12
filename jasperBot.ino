//SIM800L INITIALIZATION.
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11); 

char incomingByte; 
String inputString;
int led = 12;

//MOTION INITIALIZATION.

int ledPin = 13;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status


void setup() 
{
      //SIM800L SETUP.
      pinMode(led, OUTPUT);
     
      //Serial.begin(9600);
      mySerial.begin(9600); 
      // Check if you're currently connected to SIM800L 
      while(!mySerial.available()){
        mySerial.println("AT");
        delay(100); 
       //Serial.println("connecting....");
        }
      //Serial.println("Connected..");  
      mySerial.println("AT+CMGF=1\r\n");  //Set SMS Text Mode 
      delay(100);  
      mySerial.println("AT+CNMI=1,2,0,0,0");  //procedure, how receiving of new messages from the network
      delay(100);
      mySerial.println("AT+CMGL=\"REC UNREAD\""); // Read unread messages
      delay(100);       
      
      //MOTION SETUP.
      pinMode(ledPin, OUTPUT);      // declare LED as output
      pinMode(inputPin, INPUT);     // declare sensor as input
      Serial.begin(9600);
      
  
     }

void loop()

{ 
      
  //PIR SECTION

  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    
   //SIM800L SECTION
    if(mySerial.available()){  // Checks serial connectivity 
      delay(30);
      
      // Serial buffer
      while(mySerial.available()){
        incomingByte = mySerial.read();
        inputString += incomingByte; 
        }
        
        delay(10);
       
        //Serial.println(inputString);
        inputString.toUpperCase(); // uppercase the message received

        //turn LED ON or OFF
       if (inputString.indexOf("ANY UPDATES") > -1){
          digitalWrite(led, HIGH);
          delay(100);
            mySerial.write("AT+CMGS=\"your number\"\r\n");
            delay(100);
            mySerial.write("Hello Sir, everything seems okay.");
            mySerial.write((char)26);
            delay(100);
            ////Serial.println("SMS sent");
        } 
        
       
        else if (inputString.indexOf("HI THERE") > -1){
           mySerial.write("AT+CMGS=\"your number\"\r\n");
            delay(100);
            mySerial.write("Hey,everything seems fine here.");
            delay(100);
            mySerial.write((char)26);
            delay(100);
            
        }    
             
         else if (inputString.indexOf("SWITCH ON") > -1){
          digitalWrite(led, HIGH);
          mySerial.write("AT+CMGS=\"your number\"\r\n");
          delay(100);
          mySerial.write("It is now on boss");
          delay(100);
          mySerial.write((char)26);
          delay(100);
          //Serial.println("SMS sent");
          }
          
          else if (inputString.indexOf("SWITCH OFF") > -1){
          digitalWrite(led, LOW);
          mySerial.write("AT+CMGS=\"your number\"\r\n");
          delay(100);
          mySerial.write("It is off now boss,Are you leaving?");
          delay(100);
          mySerial.write((char)26);
          delay(1000);
          //Serial.println("SMS sent");
          }
                
        delay(50);

        //delete messages to save memory
        if (inputString.indexOf("OK") == -1){
        mySerial.println("AT+CMGDA=\"DEL ALL\"");
        delay(1000);}

        inputString = "";
  }
}
