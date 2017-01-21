#include<FreqCount.h>

int s0 = 8;
int s1 = 9;
int s2 = 10;
int s3 = 11;
int led = 12;
int flag=0;
 int diff[150];
 int count1;
 int count2;
 int x=0;
 long avg=0;

void getData()
{
   if (FreqCount.available()) 
 {
  if(flag == 0)
  {
    digitalWrite(12,HIGH);
    //delay(5);
    count1 = FreqCount.read();
    flag = 1;
  }
  else if(flag == 1)
  {
    digitalWrite(12,LOW);
    //delay(5);
    count2 = FreqCount.read();
    flag = 0;
    diff[x] = count2 - count1;
    //Serial.print("difference no:");
    
    /*Serial.println(diff[x]);
    Serial.print("count1=");
      Serial.println(count1);
      Serial.print("count2=");
      Serial.println(count2);*/
      avg = avg + diff[x];
      x=x+1;
    if(x == 10)
    {
      avg = avg/10;
      Serial.print("count1=");
      Serial.println(count1);
      Serial.print("count2=");
      Serial.println(count2);
      Serial.print("avg=");
      Serial.println(avg);
      for(x=100;x>=0;x--)
      diff[x]=0;
      
      x=0;
      /*if(avg < 2000)
      Serial.println("not white");
      else
      Serial.println("white");*/
      avg=0;
    }
    
  }
  
    
 }
}
//Pink=950
//White=1280
//black=600
//blue=800
void setup() {
  // put your setup code here, to run once:
pinMode(s0,OUTPUT);
pinMode(s1,OUTPUT);
pinMode(s2,OUTPUT);
pinMode(s3,OUTPUT);
pinMode(led,OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(7,OUTPUT);
  Serial.begin(57600);
  FreqCount.begin(10);
  digitalWrite(s0,HIGH);
  digitalWrite(s1,HIGH);
  digitalWrite(s2,HIGH);
  digitalWrite(s3,LOW);

}

void loop() {
  
 getData();
 
 

}

