#include <LiquidCrystal.h>

LiquidCrystal lcd(32, 33, 25, 27, 13, 14);  // RS, E, D4, D5, D6, D7
char data[17];
const int trigPin = 26;
const int echoPin = 34;
const int button  = 23;
const int  buzzer  = 22;
int flag=0;
void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  //lcd.clear();
  //lcd.setCursor(0, 0);
  //lcd.print("HC-SR04 Sensor");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(button,INPUT_PULLUP);
  pinMode(buzzer,OUTPUT);
}

void loop() {
    if (flag==0){
      if (digitalRead(button)==LOW){
        delay(200);
        flag=1;
         }
      lcd.setCursor(0, 0);
      lcd.print("Safe Mode :OFF");
        
     }

    
    if (flag==1)
    { 
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Safe Mode :ON");
      lcd.setCursor(0, 1);
      lcd.print("NO Object!");
      ///////////////////////////////sesore
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

      long a = pulseIn(echoPin, HIGH,30000);
      float b = (a * 0.034) / 2;

      Serial.println(b);
      
          if (digitalRead(button)==LOW){
              delay(200);
              flag=0;
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("Safe Mode :OFF");
            }

       

     
        if (b<20){
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Safe Mode :ON");
          lcd.setCursor(0, 1);
          lcd.print("Object Detected!");
          digitalWrite(buzzer, HIGH);
          delay(50);
          digitalWrite(buzzer, LOW);
              if (digitalRead(button)==LOW){
                delay(200);
                flag=0;
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("Safe Mode :OFF");
                lcd.setCursor(0, 1);
                lcd.print("Object Detected!");
              }
        }  
        
      }//flag=1
      delay(50);

         
      
        
    
    
  
}//loop
