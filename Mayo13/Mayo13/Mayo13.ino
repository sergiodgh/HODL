//Menú de selección del LED en un menú de control
//Sergio Guevara 
//13 de Mayo

#define butUp     12     //Botón ARRIBA al pin 12
#define butDown   11     //Botón ABAJO al pin 11
#define butP    10       //Botón SELECT en el pin 10
#define butM       9     //no se usa en este ejemplo
#define LampRed   13     //LED rojo al pin 13
#define LampRed2    1    //LED verde al pin 1
#define LampRele     8   //Relè al pin 8
#define PhotoSensor A0   //sensor de temperatura al pin analogico A0

// Funciones de los distintos ciclos
void changeMenu();
void dispMenu();
void mostraMsg();
void controlLed();
void controlLed2();
void controlRele();
void temperatura();

// Variables globales
char menu = 0x01;
char set1 = 0x00, set2 = 0x00 , set3 = 0x00;
boolean t_butUp, t_butDown, t_butP, t_butM;
int sensorValue = 0;
int reading = 0;
int sensorPin = A0;

//DISPLAY 

#include <LiquidCrystal.h>

LiquidCrystal lcd ( 2,   //RS
                    3,  //EN
                    4,  //D4
                    5,  //D5
                    6,  //D6
                    7); //D7 

void setup() {
  
  lcd.begin(16, 2);
  for (char i=9; i<13; i++){        // Entrada de botón
    
      pinMode(i, INPUT_PULLUP);
    
  }
  
  pinMode(LampRed, OUTPUT);         //LED ROJO
  pinMode(LampRed2, OUTPUT);        //LED VERDE
  pinMode(LampRele, OUTPUT);        //RELE
              
  digitalWrite (LampRele, HIGH);    // Establezca inicialmente el relé en el estado Alto (activo)
  
  t_butUp   = 0x00;             //Inicializa la variable como cero
  t_butDown = 0x00;
  t_butP  = 0x00;
  t_butM  = 0x00;
  

}

void loop() {
  
  
  changeMenu();               //Menú de cambio
  
  dispMenu();               //Seleccione el menú
  

}


//Función

void changeMenu(){
  
  if(digitalRead(butUp) == 0x00){       // Establece la variable en 1 si presionas el botón ARRIBA
    
    t_butUp = 0x01;
    
  }
  
   if(digitalRead(butDown) == 0x00){      // Establece la variable en 1 si presionas el botón ABAJO
    
    t_butDown = 0x01;
    
  }
  
  if(digitalRead(butUp) && t_butUp){
    
    t_butUp = 0x00;
    
    lcd.clear();        //Limpia la LCD
    
    menu++;
     
    if(menu > 0x04){
      
      menu = 0x01;
    }
  }
  
  if(digitalRead(butDown) && t_butDown){
    
    t_butDown = 0x00;
    
    lcd.clear();
    
    menu--;
     
    if(menu < 0x01){
      
      menu = 0x04;
    }
  }    
  
}



void dispMenu(){
  
  switch(menu){
    
    case 0x01:
        controlLed();              //Función de control LED1
      break;
    case 0x02:
      controlRele();               //Función de control de relé
      break;
    case 0x03:
      temperatura();               //Función de control de temperatura
      break;
    case 0x04:
        controlLed2();             //Función de control LED2
      break;
  }
}


                         // * Ciclo para función de control LED1 * //
void controlLed(){
 
  lcd.setCursor(0,0);
  lcd.print("PRENDA LED 1");
  
  if(digitalRead(butP) == 0x00){
   
    t_butP = 0x01;
    
  }
  
  if(digitalRead(butM) == 0x00){
   
    t_butM = 0x01;
    
  }
  
  if(digitalRead(butP) && t_butP){
    
    t_butP = 0x00;
    set1++;

    
    if(set1 > 2){
      
      set1 = 0x01;
    }
    
    switch(set1){
      
      case 0x01:
        lcd.clear();
        lcd.setCursor(0,1);
        digitalWrite (LampRed, HIGH);  //Enciende el led rojo
        lcd.print("LED ROJO ON");
        break;
      case 0x02:
        lcd.clear();
        lcd.setCursor(0,1);
        digitalWrite (LampRed, LOW);  //Apaga el led rojo
      break;
    }
  }
}


                         // * Ciclo para la función de control de relé * /
void controlRele(){
  
    
  lcd.setCursor(0,0);
  lcd.print("RELE");
  
  if(digitalRead(butP) == 0x00){
   
    t_butP = 0x01;
    
  }
  
  if(digitalRead(butM) == 0x00){
   
    t_butM = 0x01;
    
  }
  
  if(digitalRead(butP) && t_butP){
    
    t_butP = 0x00;
    set2++;

    
    if(set2 > 2){
      
      set2 = 0x01;
    }
    
    switch(set2){
      
      case 0x01:
        lcd.clear();
        lcd.setCursor(0,1);
        digitalWrite (LampRele, LOW);
        lcd.print("RELE ON");
        break;
      case 0x02:
        lcd.clear();
        lcd.setCursor(0,1);
        digitalWrite (LampRele, HIGH);
        lcd.print("RELE OFF");
      break;
    }
  }
}

                         // * Ciclo para la función de control de TEMPERATURA * /
void temperatura(){
  reading = analogRead(sensorPin);
  int celsius = reading/2;
  lcd.setCursor(0, 0);
  lcd.print("Temperatura: "); 
  lcd.setCursor(0,1);
  lcd.print(celsius, DEC);
  lcd.print((char)223);
  lcd.print("C");
  
}


                         // * Ciclo para la función de control del LED verde * /
void controlLed2(){
 
  
  lcd.setCursor(0,0);
  lcd.print("PRENDA LED 2");
  
  if(digitalRead(butP) == 0x00){
   
    t_butP = 0x01;
    
  }
  
  if(digitalRead(butM) == 0x00){
   
    t_butM = 0x01;
    
  }
  
  if(digitalRead(butP) && t_butP){
    
    t_butP = 0x00;
    set3++;

    
    if(set3 > 2){
      
      set3 = 0x01;
    }
    
    switch(set3){
      
      case 0x01:
        lcd.clear();
        lcd.setCursor(0,1);
        digitalWrite (LampRed2, HIGH);
        lcd.print("LED VERDE ON");
        break;
      case 0x02:
        lcd.clear();
        lcd.setCursor(0,1);
        digitalWrite (LampRed2, LOW);
        lcd.print("LED VERDE OFF");
      break;
    }
  }
}
