#include <Sim800l.h>

#include <SoftwareSerial.h>

String phoneNumber = "063992380577";

Sim800l Sim800l(;
String textSms, numberSms;

char* texto = "Sensor acionado!";
char* numero = "063992380577";

int blueLed = 8;
int greenLed = 9;
int redLed =  10;

//State of security alert
//0 - disable
//1 - enable
//2 - sensor violated
int AlertState = 0;

// Pin where RF Module is connected
byte pinRF = 7;

boolean startbit;
boolean dataok;
boolean anticodeok;

int counter;  //received bits counter: 22 of Address + 2 of Data + 4 of EndCode (Anti-Code)
int lambda;  // on pulse clock width (if fosc = 2KHz than lambda = 500 us)
int dur0, dur1;  // pulses durations (auxiliary)

unsigned long buffer=0;  //buffer for received data storage

void setup(){ 
  pinRF = 7;
  
  Serial.begin(19200);  
  //SIM900.begin(19200); 
  Sim800l.begin(); // initializate the library.
  //delay(2500);
  
  //Serial.println("GSM Iniciado");

  pinMode(pinRF, INPUT);
  //pinMode(13, OUTPUT);

  //define RGB led light mode
  //pinMode(greenLed, OUTPUT);
  //pinMode(blueLed, OUTPUT);
  //pinMode(redLed, OUTPUT);

  ChangeLedsColor(HIGH, HIGH, HIGH);
}

/*
void Send_SMS(String msg) {   
  Serial.println("AT+CMGF=1\r");
  SIM900.print("AT+CMGF=1\r"); 
  delay(100); 
  SIM900.println("AT+CMGS=\""+ phoneNumber + "\""); 
  Serial.println("AT+CMGS=\""+ phoneNumber + "\"");
  delay(100); 
  SIM900.println(msg);
  Serial.println(msg);
  delay(100); 
  SIM900.println((char)26); 
  Serial.println((char)26);
  delay(100);
  SIM900.println();
  Serial.println();
  delay(1000); 
}
*/

void AlertAndNotificated() {
  ChangeLedsColor(HIGH, HIGH, HIGH);
  ChangeLedsColor(LOW, HIGH, HIGH);
  delay(200);
  ChangeLedsColor(HIGH, HIGH, HIGH);
  delay(200);
  ChangeLedsColor(LOW, HIGH, HIGH);
  delay(200);
  ChangeLedsColor(LOW, HIGH, HIGH);
  delay(200);
  ChangeLedsColor(LOW, HIGH, HIGH);
  delay(200);
  ChangeLedsColor(LOW, HIGH, HIGH);
  ChangeLedsColor(HIGH, HIGH, HIGH);
  Serial.println("AlertAndNotificated");
}

void DefaultState() {
  ChangeLedsColor(HIGH, HIGH, HIGH);  
  Serial.println("Normal State");
}

void ChangeLedsColor(int Red, int Green, int Blue) {
  digitalWrite(redLed, Red);
  digitalWrite(greenLed, Green);
  digitalWrite(blueLed, Blue);
}

void readRFSensor() {
  //digitalWrite(13, digitalRead(pinRF)); //blink de onboard LED when receive something

  // Check the PILOT CODE until START BIT;
  if (!startbit)
  {
    dur0 = pulseIn(pinRF, LOW);  //Check how long DOUT was "0" (ZERO) (refers to PILOT CODE)        
    
    if((dur0 > 9200) && (dur0 < 13800) && !startbit) //If time at "0" is between 9200 us (23 cycles of 400us) and 13800 us (23 cycles of 600 us).
    {    
      lambda = dur0 / 23;  //calculate wave length - lambda      
      dur0 = 0;
      buffer = 0;
      counter = 0;      
      dataok = false;
      startbit = true;
    }
  }

  // If Start Bit is OK, then starts measure os how long the signal is level "1" and check is value is into acceptable range.
  if (startbit && !dataok && counter < 28)
  {
    ++counter;
    
    dur1 = pulseIn(pinRF, HIGH);
    
    if((dur1 > 0.5 * lambda) && (dur1 < (1.5 * lambda)))  //If pulse width at "1" is between "0.5 and 1.5 lambda", means that pulse is only one lambda, so the data é "1".
    {
      buffer = (buffer << 1) + 1;      // add "1" on data buffer
    }
    else if((dur1 > 1.5 * lambda) && (dur1 < (2.5 * lambda)))  //If pulse width at "1" is between "1.5 and 2.5 lambda", means that pulse is two lambdas, so the data é "0".
    {
      buffer = (buffer << 1);       // add "0" on data buffer
    }
    else
    {
      //Reset the loop
      startbit = false;
      ChangeLedsColor(HIGH, HIGH, HIGH);
    }
  }
  
  //Check if all 28 bits were received (22 of Address + 2 of Data + 4 of Anti-Code)
  if (counter==28) 
  { 
    // Check if Anti-Code is OK (last 4 bits of buffer equal "0101")
    if ((bitRead(buffer, 0) == 1) && (bitRead(buffer, 1) == 0) && (bitRead(buffer, 2) == 1) && (bitRead(buffer, 3) == 0))
    {
      anticodeok = true;
    }
    else
    {      
      startbit = false; //Reset the loop
      ChangeLedsColor(HIGH, HIGH, HIGH);
    }
    
    if (anticodeok)
    {
      dataok = true;      
      counter = 0;
      startbit = false;
      anticodeok = false;

      unsigned long addr = buffer >> 6;

      Serial.print("Data: ");
      Serial.println(buffer, BIN);      
      Serial.print("-Address: ");
      Serial.println(addr, HEX);      
      Serial.println("-Button1: " + (String)bitRead(buffer, 4));
      Serial.println("-Button2: " + (String)bitRead(buffer, 5));
      Serial.println("-----------------------------------");
      ChangeLedsColor(LOW, HIGH, HIGH);
      
      if (String(addr, HEX) == "2061CD"){
        Serial.println("TESTE...");
      }
    }
  }
}

void blikRGBLed() {
  ChangeLedsColor(HIGH, HIGH, HIGH);
  delay(500);
  ChangeLedsColor(HIGH, LOW, HIGH);
  delay(500);
  ChangeLedsColor(HIGH, HIGH, HIGH);
}

void loop()
{
  if (AlertState == 0) {
    //ChangeLedsColor(HIGH, HIGH, HIGH);
    //blikRGBLed();
    //Send_SMS("Sensor violado");
    Sim800l.sendSms(numero, texto);
    delay(15000);
  }
  else if (AlertState == 1) {
    
  }
  else if (AlertState == 2) {
    
  }
  
  readRFSensor();
  //delay(1000);
}
