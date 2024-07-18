// Project Designed By Setsom Tehnologies

// BLYNK APP CONTROL
#define BLYNK_TEMPLATE_ID "TMPLm0r3NCsv"
#define BLYNK_DEVICE_NAME "IOT BASED TRAFFIC LIGHT MONITORING SYSTEM"
#define BLYNK_AUTH_TOKEN "yCFxYEVAvqQBtfR3GZY2LSaQSzIPF-YT"


// BLYNK AND ESP32 LIBRARY
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <SimpleTimer.h>
//---------------------------------------------------------//
BlynkTimer timer;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Setsom technologies ";
char pass[] = "50842629";



//4 way automatic traffic light signals arduino code by Engr. Abdullahi Mowlid.
int G4=23;
int Y4=22;
int R4=21;

int G3=19;
int Y3=18;
int R3=5;

int G2=17;
int Y2=16;
int R2=4;

int G1=0;
int Y1=2;
int R1=15;

// sensors ir
int irstr11 = 12;
int irstr21 = 14;
int irstr22 = 27;
int irstr31 = 26;
int irstr41 = 25;
int irstr42 = 33;


// storage data
int Street1Ir_1;
int Street2Ir_1;
int Street2Ir_2;
int Street3Ir_1;
int Street4Ir_1;
int Street4Ir_2;

void setup() 
{
  pinMode(irstr11,INPUT);
  pinMode(irstr21,INPUT);
  pinMode(irstr22,INPUT);
  pinMode(irstr31,INPUT);
  pinMode(irstr41,INPUT);
  pinMode(irstr42,INPUT);
  
  pinMode(G1, OUTPUT);
  pinMode(Y1, OUTPUT);
  pinMode(R1, OUTPUT);
  
  pinMode(G2, OUTPUT);
  pinMode(Y2, OUTPUT);
  pinMode(R2, OUTPUT);
  
  pinMode(G3, OUTPUT);
  pinMode(Y3, OUTPUT);
  pinMode(R3, OUTPUT);
  
  pinMode(G4, OUTPUT);
  pinMode(Y4, OUTPUT);
  pinMode(R4, OUTPUT);

  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  
  digitalWrite(R1, 1); 
  Blynk.virtualWrite(V0, HIGH);
  digitalWrite(R2, 1);
  Blynk.virtualWrite(V3, HIGH);
  digitalWrite(R3, 1); 
  Blynk.virtualWrite(V6, HIGH);
  digitalWrite(R4, 1);
  Blynk.virtualWrite(V9, HIGH);
  delay(4000); 
  digitalWrite(Y1, 1);
  Blynk.virtualWrite(V2, HIGH);
  delay(2000);  

  timer.setInterval(10000L, Traffic_Light);
 // timer.setInterval(300L, SendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}

void Traffic_Light(){

  Street1Ir_1 = digitalRead(irstr11);
  Street2Ir_1 = digitalRead(irstr21);
  Street2Ir_2 = digitalRead(irstr22);
  Street3Ir_1 = digitalRead(irstr31);
  Street4Ir_1 = digitalRead(irstr41);
  Street4Ir_2 = digitalRead(irstr42);

  digitalWrite(Y4, 0);
  Blynk.virtualWrite(V10, LOW);
  digitalWrite(R4, 1);
  Blynk.virtualWrite(V9, HIGH);
  
   if (Street1Ir_1==LOW){
    Blynk.virtualWrite(V12, HIGH);  
    }
   else {
    Blynk.virtualWrite(V12, LOW); 
   }
 
    digitalWrite(R1, 0);
    Blynk.virtualWrite(V0, LOW);
    digitalWrite(G1, 1);
    Blynk.virtualWrite(V2, HIGH);
    digitalWrite(Y1, 0);
    Blynk.virtualWrite(V1, LOW);
    delay(15000); 
  
  digitalWrite(G1, 0);
  Blynk.virtualWrite(V2, LOW);
  delay(500);
  digitalWrite(G1, 1);
  Blynk.virtualWrite(V2, HIGH);
  delay(500);
  digitalWrite(G1, 0);
  Blynk.virtualWrite(V2, LOW);
  delay(500);
  digitalWrite(G1, 1);
  Blynk.virtualWrite(V2, HIGH);
  delay(500);
  digitalWrite(G1, 0);
  Blynk.virtualWrite(V2, LOW);
  delay(500);
  digitalWrite(G1, 1);
  Blynk.virtualWrite(V2, HIGH);
  delay(500);
  
  digitalWrite(Y1, 1);
  Blynk.virtualWrite(V1, HIGH);
  digitalWrite(G1, 0);
  Blynk.virtualWrite(V2, LOW);
  delay(2000);
  
  digitalWrite(R1, 1);
  Blynk.virtualWrite(V0, HIGH);
  digitalWrite(Y1, 0);
  Blynk.virtualWrite(V1, LOW);
  delay(2000);
  digitalWrite(Y2, 1);
  Blynk.virtualWrite(V4, HIGH);
  delay(2000);


   if(Street2Ir_1==LOW){
    Blynk.virtualWrite(V13, HIGH);    
  }
   else {         
     Blynk.virtualWrite(V13, LOW); 
  }
   if(Street2Ir_2==LOW){
    Blynk.virtualWrite(V14, HIGH);    
  }
   else {         
     Blynk.virtualWrite(V14, LOW); 
  }
digitalWrite(R2, 0);
Blynk.virtualWrite(V3, LOW);
digitalWrite(G2, 1);
Blynk.virtualWrite(V5, HIGH);
digitalWrite(Y2, 0);
Blynk.virtualWrite(V4, LOW);
delay(15000);

digitalWrite(G2, 0);
Blynk.virtualWrite(V5, LOW);
delay(500);
digitalWrite(G2, 1);
Blynk.virtualWrite(V5, HIGH);
delay(500);
digitalWrite(G2, 0);
Blynk.virtualWrite(V5, LOW);
delay(500);
digitalWrite(G2, 1);
Blynk.virtualWrite(V5, HIGH);
delay(500);
digitalWrite(G2, 0);
Blynk.virtualWrite(V5, LOW);
delay(500);
digitalWrite(G2, 1);
Blynk.virtualWrite(V5, HIGH);
delay(500);

digitalWrite(G2, 0);
Blynk.virtualWrite(V5, LOW);
digitalWrite(Y2, 1);
Blynk.virtualWrite(V4, HIGH);
delay(2000);
digitalWrite(R2, 1);
Blynk.virtualWrite(V3, HIGH);
digitalWrite(Y2, 0);
Blynk.virtualWrite(V4, LOW);
delay(2000);
digitalWrite(Y3, 1);
Blynk.virtualWrite(V7, HIGH);
delay(2000);


  if(Street3Ir_1==LOW){
    Blynk.virtualWrite(V15, HIGH);    
  }
  else {
     Blynk.virtualWrite(V15, LOW);
  }
digitalWrite(R3, 0);
Blynk.virtualWrite(V6, LOW);
digitalWrite(G3, 1);
Blynk.virtualWrite(V8, HIGH);
digitalWrite(Y3, 0);
Blynk.virtualWrite(V7, LOW);
delay(15000);

digitalWrite(G3, 0);
Blynk.virtualWrite(V8, LOW);
delay(500);
digitalWrite(G3, 1);
Blynk.virtualWrite(V8, HIGH);
delay(500);
digitalWrite(G3, 0);
Blynk.virtualWrite(V8, LOW);
delay(500);
digitalWrite(G3, 1);
Blynk.virtualWrite(V8, HIGH);
delay(500);
digitalWrite(G3, 0);
Blynk.virtualWrite(V8, LOW);
delay(500);
digitalWrite(G3, 1);
Blynk.virtualWrite(V8, HIGH);
delay(500);

digitalWrite(G3, 0);
Blynk.virtualWrite(V8, LOW);
digitalWrite(Y3, 1);
Blynk.virtualWrite(V7, HIGH);
delay(2000);
digitalWrite(R3, 1);
Blynk.virtualWrite(V6, HIGH);
digitalWrite(Y3, 0);
Blynk.virtualWrite(V7, LOW);
delay(2000);
digitalWrite(Y4, 1);
Blynk.virtualWrite(V10, HIGH);
delay(2000);

 if(Street4Ir_1==LOW){
    Blynk.virtualWrite(V16, HIGH);    
  }
  else{ 
     Blynk.virtualWrite(V16, LOW); 
  }
 if(Street4Ir_2==LOW){
    Blynk.virtualWrite(V17, HIGH);    
  }
 else{ 
     Blynk.virtualWrite(V17, LOW); 
  }
digitalWrite(R4, 0);
Blynk.virtualWrite(V9, LOW);
digitalWrite(G4, 1);
Blynk.virtualWrite(V11, HIGH);
digitalWrite(Y4, 0);
Blynk.virtualWrite(V10, LOW);
delay(15000);

digitalWrite(G4, 0);
Blynk.virtualWrite(V11, LOW);
delay(500);
digitalWrite(G4, 1);
Blynk.virtualWrite(V11, HIGH);
delay(500);
digitalWrite(G4, 0);
Blynk.virtualWrite(V11, LOW);
delay(500);
digitalWrite(G4, 1);
Blynk.virtualWrite(V11, HIGH);
delay(500);
digitalWrite(G4, 0);
Blynk.virtualWrite(V11, LOW);
delay(500);
digitalWrite(G4, 1);
Blynk.virtualWrite(V11, HIGH);
delay(500);

digitalWrite(G4, 0);
Blynk.virtualWrite(V11, LOW);
digitalWrite(Y4, 1);
Blynk.virtualWrite(V10, HIGH);
delay(2000);
digitalWrite(R4, 1);
Blynk.virtualWrite(V9, HIGH);
digitalWrite(Y4, 0);
Blynk.virtualWrite(V10, LOW);
delay(2000);
digitalWrite(Y1, 1);
Blynk.virtualWrite(V1, HIGH);
delay(2000);
digitalWrite(R1, 0);
Blynk.virtualWrite(V0, LOW);
digitalWrite(G1, 1);
Blynk.virtualWrite(V2, HIGH);
digitalWrite(Y1, 0);
Blynk.virtualWrite(V1, LOW);
delay(2000);
 
}
