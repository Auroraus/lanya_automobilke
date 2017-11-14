#include <Servo.h>
Servo myservo1;
Servo myservo2;
int power=7;
int leftre=6;
int rightre=5;
int pos=120;
int po=120;
void left(){
  digitalWrite(power,LOW);
  digitalWrite(leftre,LOW);
digitalWrite(rightre,HIGH);
}
void sto(){
   digitalWrite(power,HIGH);
   digitalWrite(leftre,HIGH);
digitalWrite(rightre,HIGH);
}
void right(){
   digitalWrite(power,LOW);
  digitalWrite(leftre,HIGH);
digitalWrite(rightre,LOW);
}
void bleft(){
  digitalWrite(power,HIGH);
  digitalWrite(leftre,LOW);
digitalWrite(rightre,HIGH);
}
void bright(){
   digitalWrite(power,HIGH);
  digitalWrite(leftre,HIGH);
digitalWrite(rightre,LOW);
}
void forward(){
   digitalWrite(power,LOW);
  digitalWrite(leftre,HIGH);
digitalWrite(rightre,HIGH);
}
void back(){
   digitalWrite(power,HIGH);
  digitalWrite(leftre,LOW);
digitalWrite(rightre,LOW);
}
void xdup()
{
 pos=pos+5;
 if(pos<180)
 {
 myservo1.write(pos);              // tell servo to go to position in variable 'pos' 
}
}
void sdup()
{
 po=po+5;
 if(po<180)
 {
 myservo2.write(po);              // tell servo to go to position in variable 'pos'
 }
}
void xddown()
{
 pos=pos-5;
 if(pos>0)
 {
 myservo1.write(pos);              // tell servo to go to position in variable 'pos'
   
}}
void sddown()
{
 po=po-5;
 if(po>0)
 {
 myservo2.write(po);              // tell servo to go to position in variable 'pos'
}
}
void setup() {
  // put your setup code here, to run once:
pinMode(leftre,OUTPUT);
pinMode(rightre,OUTPUT);
pinMode(power,OUTPUT);
myservo1.attach(9);
myservo2.attach(10);
myservo1.write(0); 
myservo2.write(90); 
Serial.begin(9600);
digitalWrite(power,HIGH);
digitalWrite(leftre,HIGH);
digitalWrite(rightre,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available())
{char i=Serial.read();
switch(i)
{
  case 'a':{left();break;}
  case 'b':{right();break;}
  case 'c':{forward();break;}
  case 'd':{sto();break;}
  case 'e':{back();break;}
  case 'f':{bleft();break;}
  case 'g':{bright();break;}
  case 'h':{xdup();break;}
  case 'i':{sdup();break;}
  case 'j':{xddown();break;}
  case 'k':{sddown();break;}
}
}
}
