#include <RTClib.h>
#include <Wire.h>
#include <Servo.h>

Servo myservo;
RTC_DS3231 rtc;
char t[32];

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  
  //rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
  //rtc.adjust(DateTime(2023, 5, 11, 15, 49, 00));

  myservo.attach(D5);
}

void loop()
{
  DateTime now = rtc.now();

  int pos;

  sprintf(t, "%02d:%02d:%02d %02d/%02d/%02d", now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year());  
  Serial.print(F("Date/Time: "));
  Serial.println(t);

  if (now.hour() == 16 && now.minute() == 35) //Alarm Configuration
  {
    myservo.write(180);              
    delay(15);                       
  }
  else if (now.hour() == 16 && now.minute() == 36) 
  {
    myservo.write(90);              
    delay(15);                       
  }

  delay(1000);
}
