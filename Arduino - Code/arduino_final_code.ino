#include <LiquidCrystal.h>

#include "DHT.h"

#define DHTPIN 25   

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
long int seconds=0; 
int minutes=0; 
int hours=0; 
int set=0; 
int reset=0; 
LiquidCrystal LCD(22,21,5,18,23,19);
int v;
int led = 2;
DHT dht(DHTPIN, DHTTYPE);
void timepass()
{
  LCD.setCursor(0,1);
  LCD.print("TIME: ");
  //sets the cursor to 0th column and 1st row,numbering starts from 0 
 
if(hours<10)        //suppose 4 
{ 
LCD.print("0");     //LCD first prints 0 and stopwatch shows 0 
LCD.print(hours);
LCD.print(":");//LCD then prints 4. So value printed is 04 stopwatch shows 04 
} 
else 
{ 
LCD.print(hours); 
LCD.print(":");
}  
if(minutes<10) 
{ 
LCD.print("0"); 
LCD.print(minutes); 
LCD.print(":"); 
} 
else 
{ 
LCD.print(minutes); 
LCD.print(":"); 
} 
if(seconds<10) 
{ 
LCD.print("0"); 
LCD.print(seconds); 

} 
else 
{ 
LCD.print(seconds); 

} 
}


void stop ()
{
 LCD.setCursor(0,1); 
  LCD.print("TIME: ");//sets the cursor to 0th column and 1st row,numbering starts from 0 
 
if(hours<10)        //suppose 4 
{ 
LCD.print("0");     //LCD first prints 0 and stopwatch shows 0 
LCD.print(hours);
LCD.print(":");//LCD then prints 4. So value printed is 04 stopwatch shows 04 
} 
else 
{ 
LCD.print(hours); 
LCD.print(":");
}  
if(minutes<10) 
{ 
LCD.print("0"); 
LCD.print(minutes); 
LCD.print(":"); 
} 
else 
{ 
LCD.print(minutes); 
LCD.print(":"); 
} 
if(seconds<10) 
{ 
LCD.print("0"); 
LCD.print(seconds); 

} 
else 
{ 
LCD.print(seconds); 

} 

}

void setClock() 
{ 
seconds++;       //counts seconds from 0 
//delay(1000);     //a delay of 1000 milliseconds is given for each second count 
if (seconds>59) 
{ 
seconds=0;      //whenever second is greater than 59 than second is made equal to 
minutes++;     // zero and a minute is counted for it 
} 
if (minutes>59) 
{hours++; 
minutes=0; 
} 

if(hours>23) 
{ 
hours=0; 
} 
}

void setup() {
  
  pinMode(27, OUTPUT);
  Serial.begin(115200);
  LCD.begin(16, 2); 
  //Serial.println(F("DHTxx test!"));
   
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  


  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  v = Serial.readString().toInt();
  Serial.println(led);
  Serial.println(v);
  if (v == 1)
  {
    led = 1;
  }
  if (v == 2)
  {
    led = 2;
  }
  if (led == 1)
{
digitalWrite(27,LOW);
LCD.setCursor(0,0);
LCD.print("TEMP: ");
LCD.print(t);
setClock();
  
timepass();
}
if (led == 2)
  {
    digitalWrite(27,HIGH);
    LCD.setCursor(0,0);
    LCD.print("TEMP: ");
    LCD.print(t);
    stop();
  }

  if (t>29)
  {
    digitalWrite(27,HIGH);
    
  }
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    //Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  Serial.println(t);
}
