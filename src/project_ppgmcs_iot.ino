#include <SoftwareSerial.h>

//Phone number brazilian format DDD+PHONENUMBER, example: 063999999999
String phoneNumber = "063992380577";

int greenLed = 2;
int blueLed = 3;
int redLed =  4;

int SensorDoorState = 0;
int SensorMoveState = 0;

int SensorMove = 6;
int SensorDoor = 5;

char incoming_char=0;
int salir = 0;

//State of security alert
//0 - Normal
//1 - Alert but not send notification
//2 - Alert and notificated
int AlertState = 1;

//Configure GMS Serial port
SoftwareSerial SIM900(7, 8); 

void setup() {
  Serial.begin(19200);
  SIM900.begin(19200); 
  delay(2500); 
  Serial.begin(19200);

  Serial.println("GSM Iniciado");
  
  //define RGB led light mode
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(redLed, OUTPUT);

  //define input sensor pin
  pinMode(SensorMove, INPUT_PULLUP);
  pinMode(SensorDoor, INPUT_PULLUP);
  
  ChangeLedsColor(HIGH, HIGH, HIGH);
}

void Send_SMS() { 	
	SIM900.print("AT+CMGF=1\r"); 
	delay(100);	
	SIM900.println("AT+CMGS=\""+ phoneNumber + "\""); 
	delay(100);	
	SIM900.println("Sensor violated"); 
	delay(100);	
	SIM900.println((char)26); 
	delay(100);
	SIM900.println();	
	delay(5000); 
}

void loop() {  
  SensorDoorState = digitalRead(SensorDoor); 
  SensorMoveState = digitalRead(SensorMove);
  SensorMoveState = LOW;
  
  if (SensorDoorState == HIGH || SensorMoveState == HIGH) {
    ChangeLedsColor(LOW, HIGH, HIGH);
    Serial.println("Sensor violated");
    ChangeLedsColor(LOW, HIGH, HIGH);
    Send_SMS();
    delay(5000);
  }
  else {
    ChangeLedsColor(HIGH, LOW, HIGH);
  }
}

void ChangeLedsColor(int Red, int Green, int Blue) {
  digitalWrite(redLed, Red);
  digitalWrite(greenLed, Green);
  digitalWrite(blueLed, Blue);
}

void DefaultState() {
  ChangeLedsColor(HIGH, LOW, HIGH);
  delay(700);
  ChangeLedsColor(HIGH, HIGH, HIGH);
  delay(700);
  Serial.println("Normal State");
}

void AlertButNotSendNotification() {
  ChangeLedsColor(LOW, HIGH, HIGH);
  delay(300);
  ChangeLedsColor(HIGH, HIGH, HIGH);
  delay(300);
  Serial.println("AlertButNotSendNotification");
}

void AlertAndNotificated() {
  ChangeLedsColor(LOW, HIGH, HIGH);
  delay(700);
  ChangeLedsColor(HIGH, HIGH, HIGH);
  delay(100);
  ChangeLedsColor(HIGH, HIGH, LOW);
  delay(700);
  ChangeLedsColor(HIGH, HIGH, HIGH);
  Serial.println("AlertAndNotificated");
}
