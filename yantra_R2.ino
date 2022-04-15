// FOR THE ROBOT R2

import processing.serial.*;
Serial myPort;
String val;
#include <SPI.h>
#include <WiFi101.h>
#define enA 5//Enable1 L293 Pin enA 
#define in1 6 //Motor1  L293 Pin in1 
#define in2 7 //Motor1  L293 Pin in1 
#define in3 9 //Motor2  L293 Pin in1 
#define in4 10 //Motor2  L293 Pin in1 
#define enB 8 //Enable2 L293 Pin enB 
#define R_S 4//colour sensor Right
#define L_S 4 //colour sensor Left

boolean firstContact = false;

void setup(){ 
pinMode(R_S, INPUT); 
pinMode(L_S, INPUT); 
pinMode(enA, OUTPUT); 
pinMode(in1, OUTPUT); 
pinMode(in2, OUTPUT); 
pinMode(in3, OUTPUT); 
pinMode(in4, OUTPUT); 
pinMode(enB, OUTPUT);
digitalWrite(enA, HIGH); 
digitalWrite(enB, HIGH); 
delay(1000);
}

char ssid[] = "***";         

int status = WL_IDLE_STATUS;
IPAddress server(*.*.*.*);

WiFiClient client;

void setup() {
  delay(2000);
  Serial.begin(9600);
  Serial.println("Attempting to connect to WPA network...");
  Serial.print("SSID: ");
  Serial.println(ssid);

  status = WiFi.begin(ssid);
  if ( status != WL_CONNECTED) { 
    Serial.println("Couldn't get a wifi connection");
    // don't do anything else:
    while(true);
  } 
  else {
    Serial.println("Connected to wifi");
    Serial.println("\nStarting connection...");
    // if you get a connection, report back via serial:
    if (client.connect(server, ****)) {
      Serial.println("connected");

      client.println();
      client.flush();
    }
  }
}
void draw()
{
  if ( myPort.available() > 0) 
  {
  val = myPort.readStringUntil('\n');
  } 
println(val);
}
void serialEvent( Serial myPort) {
val = myPort.readStringUntil('\n');
if (val != null) {
  val = trim(val);
  println(val);
 
  if (firstContact == false) {
    if (val.equals("A")) {
      myPort.clear();
      firstContact = true;
      myPort.write("A");
      println("contact");
    }
  }
  else { 
    println(val);

    if (mousePressed == true) 
    {                           
      myPort.write('1');        
      println("1");
    }

 
    myPort.write("A");
    }
  }
}


void loop()
{
  if (Serial.available() > 0) { 
    val = Serial.read(); 

    if(val == '1') 
    {
       ledState = !ledState; 
       digitalWrite(ledPin, ledState); 
    }
    delay(100);
  } 
    else {
    Serial.println("Hello, world!"); 
    delay(50);
    }
}

void establishContact() {
  while (Serial.available() <= 0) {
  Serial.println("A");   
  delay(300);
  }
}



void loop(){  
if((digitalRead(R_S) == 4)&&(digitalRead(L_S) == 5)){forward();}      //if Right Sensor is Blue and Left Sensor is Red then it will call forword function.
if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)){forward();}    //if Right Sensor and Left Sensor is Black then it will call forword function.
if((digitalRead(R_S) == 3)&&(digitalRead(L_S) == 4)){forward();}    //if Right Sensor is Yellow and Left Sensor is Blue then it will call forward function.
if((digitalRead(R_S) == 2)&&(digitalRead(L_S) == 2)){turnRight();}   //if Right Sensor and Left Sensor is Green then it will call turn Right function. 
if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){Stop();}      //if Right Sensor and Left Sensor are at White color then it will call Stop function.
}
void forward(){  //forword
digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 
}
void turnRight(){ //turnRight
digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin  
digitalWrite(in3, LOW);  //Left Motor backword Pin 
 digitalWrite(in4, HIGH); //Left Motor forword Pin 
}
void Stop(){ //stop
digitalWrite(in1, LOW); //Right Motor forword Pin 
digitalWrite(in2, LOW); //Right Motor backword Pin 
digitalWrite(in3, LOW); //Left Motor backword Pin 
digitalWrite(in4, LOW); //Left Motor forword Pin 
}
