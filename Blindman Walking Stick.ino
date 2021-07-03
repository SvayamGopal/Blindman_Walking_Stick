#include <Servo.h>
#include "Ultrasonic.h"
int incomingByte = 0;
int A = 2;
int B = 3;
int C = 4;
int D = 5;
Ultrasonic ultrasonicL(48, 49);
Ultrasonic ultrasonicM(50, 51);
Ultrasonic ultrasonicR(52, 53);
Ultrasonic ultrasonicT(42, 43);
Ultrasonic ultrasonicU(40, 41);
int s1 = 46;
int s2 = 47;
int s3 = 44;
int s4 = 45;
int s1Value = 0;
int s2Value = 0;
int s3Value = 0;
int s4Value = 0;
void setup()
{
  Serial.begin(9600);
  pinMode (s1, INPUT);
  pinMode (s2, INPUT);
  pinMode (s3, INPUT);
  pinMode (s4, INPUT);
}
void loop()
{
  Serial.print("Sensor Left:");
  Serial.print(ultrasonicL.Ranging(CM));
  Serial.print(" cm."); Serial.print(" ");
  Serial.print("Sensor Middle:");
  Serial.print(ultrasonicM.Ranging(CM));
  Serial.print(" cm.");
  Serial.print(" ");
  Serial.print("Sensor Right:");
  Serial.print(ultrasonicR.Ranging(CM));
  Serial.print(" cm.");
  Serial.print(" ");
  Serial.print("Sensor Top:");
  Serial.print(ultrasonicT.Ranging(CM));
  Serial.print(" cm.");
  Serial.print(" ");
  Serial.print("Sensor Top:");
  Serial.print(ultrasonicU.Ranging(CM));
  Serial.println(" cm.");
  delay(100);
  s1Value = digitalRead(s1);
  s2Value = digitalRead(s2);
  s3Value = digitalRead(s3);
  s4Value = digitalRead(s4);
  Serial.print(s1Value);
  Serial.print(" ");
  Serial.print(s2Value);
  Serial.print(" ");
  Serial.print(s3Value);
  Serial.print(" ");
  Serial.println(s4Value);
  if
  ( s1Value == LOW && s2Value == HIGH && s3Value == HIGH && s4Value
      ==
      LOW)
  {
    analogWrite(A, 100);
    analogWrite(B, 0);
    analogWrite(C, 100);
    analogWrite(D, 0);
  }
  else if
  ( s1Value == HIGH && s2Value == HIGH && s3Value == HIGH && s4Value
      ==
      LOW)
  {
    analogWrite(A, 0);
    analogWrite(B, 0);
    analogWrite(C, 100);
    analogWrite(D, 0);
  }
  else if
  ( s1Value == HIGH && s2Value == HIGH && s3Value == LOW && s4Value
      == LOW)
  {
    analogWrite(A, 0);
    analogWrite(B, 0);
    analogWrite(C, 100);
    analogWrite(D, 0);
  }
  else if
  ( s1Value == LOW && s2Value == HIGH && s3Value == HIGH && s4Value
      ==
      HIGH)
  {
    analogWrite(A, 100);
    analogWrite(B, 0);
    analogWrite(C, 0);
    analogWrite(D, 0);
  }
  else if
  ( s1Value == LOW && s2Value == LOW && s3Value == HIGH && s4Value
      ==
      HIGH)
  {
    analogWrite(A, 100);
    analogWrite(B, 0);
    analogWrite(C, 0);
    analogWrite(D, 0);
  }
  else if
  ( s1Value == LOW && s2Value == HIGH && s3Value == LOW && s4Value
      ==
      LOW)
  {
    analogWrite(A, 100);
    analogWrite(B, 0);
    analogWrite(C, 0);
    analogWrite(D, 0);
  }
  else if
  ( s1Value == HIGH && s2Value == LOW && s3Value == LOW && s4Value
      ==
      LOW)
  {
    analogWrite(A, 100);
    analogWrite(B, 0);
    analogWrite(C, 0);
    analogWrite(D, 0);
  }
  else if
  ( s1Value == LOW && s2Value == LOW && s3Value == HIGH && s4Value
      ==
      LOW) {
    analogWrite(A, 0);
    analogWrite(B, 0);
    analogWrite(C, 100);
    analogWrite(D, 0);
  }
  else if
  ( s1Value == LOW && s2Value == LOW && s3Value == LOW && s4Value ==
      HIGH)
  {
    analogWrite(A, 0);
    analogWrite(B, 0);
    analogWrite(C, 100);
    analogWrite(D, 0);
  }
  else
  {
    if (ultrasonicT.Ranging(CM) > 20)
    {
      analogWrite(A, 0); //reverse
      analogWrite(B, 70);
      analogWrite(C, 0);
      analogWrite(D, 70);
      delay(400);
      analogWrite(A, 0); //stop
      analogWrite(B, 0);
      analogWrite(C, 0);
      analogWrite(D, 0);
      delay(2000);
      analogWrite(A, 0); //reverse
      analogWrite(B, 40);
      analogWrite(C, 0);
      analogWrite(D, 40);
      delay(500);
      analogWrite(A, 0); //left
      analogWrite(B, 125);
      analogWrite(C, 125);
      analogWrite(D, 0);
      delay(800);
    }
    else if (ultrasonicU.Ranging(CM) > ultrasonicM.Ranging(CM))
      //upward stair
    {
      analogWrite(A, 0); //reverse
      analogWrite(B, 70);
      analogWrite(C, 0);
      analogWrite(D, 70);
      delay(400);
      analogWrite(A, 0); //stop
      analogWrite(B, 0);
      analogWrite(C, 0); analogWrite(D, 0);
      delay(2000);
    }
    else
    {
      if (ultrasonicL.Ranging(CM) > 30 && /*ultrasonicM.Ranging(CM) < 15
  &&*/
          ultrasonicR.Ranging(CM) > 30 && ultrasonicT.Ranging(CM) <= 20)
      {
        analogWrite(A, 40); //forward
        analogWrite(B, 0);
        analogWrite(C, 40);
        analogWrite(D, 0);
      }
      else if (ultrasonicL.Ranging(CM) < 30 && /*ultrasonicM.Ranging(CM)
  < 15
  &&*/ ultrasonicR.Ranging(CM) < 30 && ultrasonicT.Ranging(CM) <= 20)
      {
        analogWrite(A, 0); //reverse
        analogWrite(B, 40);
        analogWrite(C, 0);
        analogWrite(D, 40);
      }
      else if (ultrasonicM.Ranging(CM) < 15 && ultrasonicT.Ranging(CM)
               <= 20)
      {
        analogWrite(A, 0); //stop
        analogWrite(B, 0);
        analogWrite(C, 0);
        analogWrite(D, 0);
        delay(1000);
        analogWrite(A, 0); //reverse
        analogWrite(B, 40);
        analogWrite(C, 0);
        analogWrite(D, 40);
        delay(500);
        analogWrite(A, 0); //left
        analogWrite(B, 125);
        analogWrite(C, 125);
        analogWrite(D, 0);
        delay(800);
      }
      else if (ultrasonicL.Ranging(CM) > 30 && /*ultrasonicM.Ranging(CM)
  < 15
  &&*/ ultrasonicR.Ranging(CM) < 30 && ultrasonicT.Ranging(CM) <= 20)
      {
        analogWrite(A, 0); //left
        analogWrite(B, 100);
        analogWrite(C, 100);
        analogWrite(D, 0);
      } else if (ultrasonicL.Ranging(CM) < 30 && /*ultrasonicM.Ranging(CM)
  > 15
  &&*/ ultrasonicR.Ranging(CM) > 30 && ultrasonicT.Ranging(CM) <= 20)
      {
        analogWrite(A, 100); //right
        analogWrite(B, 0);
        analogWrite(C, 0);
        analogWrite(D, 100);
      }
      else if (ultrasonicL.Ranging(CM) < 30 && /*ultrasonicM.Ranging(CM)
  < 15
  &&*/ ultrasonicR.Ranging(CM) > 30 && ultrasonicT.Ranging(CM) <= 20)
      {
        analogWrite(A, 100); //right
        analogWrite(B, 0);
        analogWrite(C, 0);
        analogWrite(D, 100);
      }
      else if (ultrasonicL.Ranging(CM) > 30 && /*ultrasonicM.Ranging(CM)
  < 15
  &&*/ ultrasonicR.Ranging(CM) < 30 && ultrasonicT.Ranging(CM) <= 20)
      {
        analogWrite(A, 0); //left
        analogWrite(B, 100);
        analogWrite(C, 100);
        analogWrite(D, 0);
      }
    }
  }
}
