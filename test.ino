/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on NodeMCU.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right NodeMCU module
  in the Tools -> Board menu!

  For advanced settings please follow ESP examples :
   - ESP8266_Standalone_Manual_IP.ino
   - ESP8266_Standalone_SmartConfig.ino
   - ESP8266_Standalone_SSL.ino

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "6fe8ff96a2d041359ab72944191187fb";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Sid";
char pass[] = "11111111";

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  
  
  pinMode(D4,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT);
  
  digitalWrite(D4,LOW);
  digitalWrite(D5,LOW);
  digitalWrite(D6,LOW);
  digitalWrite(D7,LOW);
  
  digitalWrite(D0,LOW);
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);
  digitalWrite(D3,LOW);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);
}

void loop()
{
  Blynk.run();
  if(digitalRead(D0)==HIGH && digitalRead(D1)==LOW && digitalRead(D2)==LOW && digitalRead(D3)==LOW){
    digitalWrite(D4,HIGH);
    digitalWrite(D5,LOW);
    digitalWrite(D6,HIGH);
    digitalWrite(D7,LOW);  
  }
  else if(digitalRead(D1)==HIGH && digitalRead(D0)==LOW && digitalRead(D2)==LOW && digitalRead(D3)==LOW){
    digitalWrite(D4,HIGH);
    digitalWrite(D5,LOW);
    digitalWrite(D6,LOW);
    digitalWrite(D7,HIGH);  
  }
  else if(digitalRead(D2)==HIGH && digitalRead(D1)==LOW && digitalRead(D0)==LOW && digitalRead(D3)==LOW){
    digitalWrite(D4,LOW);
    digitalWrite(D5,HIGH);
    digitalWrite(D6,HIGH);
    digitalWrite(D7,LOW);  
  }
  else if(digitalRead(D3)==HIGH && digitalRead(D1)==LOW && digitalRead(D2)==LOW && digitalRead(D0)==LOW){
    digitalWrite(D4,LOW);
    digitalWrite(D5,HIGH);
    digitalWrite(D6,LOW);
    digitalWrite(D7,HIGH);  
  }
  else if(digitalRead(D0)==LOW && digitalRead(D1)==LOW && digitalRead(D2)==LOW && digitalRead(D3)==LOW){
    digitalWrite(D4,LOW);
    digitalWrite(D5,LOW);
    digitalWrite(D6,LOW);
    digitalWrite(D7,LOW);
 }
  
}

