#include <Wire.h> 
#include <LiquidCrystal.h>
#include <LcdBarGraph.h>


LiquidCrystal lcd(12, 11, 10, 9, 8, 7); 
LcdBarGraph lbg0(&lcd, 8, 11, 0); // 8 segmente / coloana 11/ linia 0
LcdBarGraph lbg1(&lcd, 8, 11, 1); // 8 segmente / coloana 11/ linia 1
byte cpu = 0;
byte ram = 0;
String inData;

void setup() {
  Serial.begin(9600);
  lcd.begin(20, 2);   // setare numar coloane si randuri
  lcd.setCursor(3,0);
  lcd.print("OPENMEDIAVAULT"); // ce apare la pornire pe prima linie
  lcd.setCursor(8,1);
  lcd.print("NAS"); // ce apare la pornire pe a doua linie 
  
  
}

void loop() {
    
    while (Serial.available() > 0)
    {
        char recieved = Serial.read();
        inData += recieved; // convert datele primite in string necesare afisarii
        float cpu = inData.toFloat(); // convert string data in value data
        float ram = inData.toFloat(); // convert string data in value data
  
        if (recieved == '*')
        {
            inData.remove(inData.length() -1, 1);
            lbg0.drawValue(cpu, 100); // printare valoare bargraf
            lcd.setCursor(1,0);
            lcd.print("CPU "); 
            lcd.setCursor(5,0);
            lcd.print(inData);
            lcd.setCursor(9,0);
            lcd.print("% ");
            inData = "" ; 
            
            if(inData == "DIS")
            {
              delay(0); 
            }
        } 
        
        if (recieved == '#')
        {
            inData.remove(inData.length() -1, 1);
            lbg1.drawValue(ram, 100); // printare valoare bargraf
            lcd.setCursor(1,1);
            lcd.print("RAM ");
            lcd.setCursor(5,1);
            lcd.print(inData);
            lcd.setCursor(9,1);
            lcd.print("% ");
            inData = ""; 
        }
    }
}
