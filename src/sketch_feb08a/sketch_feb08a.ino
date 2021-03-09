#include <SoftwareSerial.h>
#include <Wire.h>
#include <RtcDS3231.h>

//#define SIM800_TX 10;
//#define SIM800_RX 11;

RtcDS3231<TwoWire> Rtc(Wire);

 
//SoftwareSerial sim800(SIM800_TX,SIM800_RX);

/* void SendSMS(char celular, char msg) {  
   
  sim800.begin(9600);
  delay(1000);
   
  Serial.println("Enviando SMS, um momento...");
   
  sim800.write("AT+CMGF=1\r\n");
  delay(1000);
 
  //sim800.write("AT+CMGS=\"" + (String)celular + ""\"\r\n");
  delay(1000);
   
  sim800.write(msg);
  delay(1000);
   
  sim800.write((char)26);
  delay(1000);
     
  Serial.println("Feito");  
}
*/
void setup() {
  
  Serial.begin(115200); 
  Rtc.Begin();      
  
  RtcDateTime tempoatual = RtcDateTime(__DATE__,__TIME__);
  delay(5000);
  
  Serial.println(__DATE__); 
  delay(5000);
  
  Serial.println(__TIME__); 
  delay(5000);
  
  Rtc.SetDateTime(tempoatual); 
  
}

void loop() {
  
  RtcDateTime instante = Rtc.GetDateTime();    
   char valores[20];   
 
   sprintf(valores, "%d/%d/%d %d:%d:%d",     
          instante.Year(),   
          instante.Month(),  
          instante.Day(),    
          instante.Hour(),   
          instante.Minute(),
          instante.Second()  
         );
         
   Serial.println(valores);
   
   delay(2000);
   
}
