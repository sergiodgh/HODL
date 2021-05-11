#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int upButton = 10;
int downButton = 9;
int selectButton = 8;

int menu = 1;

int LED = 7;

void setup() {
  lcd.begin(16, 2); //aquí se inicializa la pantalla LCD

  pinMode(upButton, INPUT_PULLUP); //se definen los botones propios
  pinMode(downButton, INPUT_PULLUP);//para cada acción
  pinMode(selectButton, INPUT_PULLUP);
  
  pinMode(LED, OUTPUT);

  updateMenu();
}


// aquí se encuentra el loop y define que tan
//rápidamente reaccionan nuestros botones

void loop() {
  if (!digitalRead(downButton)) {
    menu++;
    updateMenu();
    delay(100);
    while (!digitalRead(downButton));
  }

  if (!digitalRead(upButton)) {
    menu--;
    updateMenu();
    delay(100);
    while (!digitalRead(upButton));
  }

  if (!digitalRead(selectButton)) {
    execute();
    updateMenu();
    delay(100);
    while (!digitalRead(selectButton));
  }  
}


//esta parte es el menú hecho a partir de la estructura case
//en donde seleccionaremos si queremos prender o apagar el LED

void updateMenu() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      lcd.print(">LED ON");
      lcd.setCursor(0, 1);
      lcd.print(" LED OFF");
      break;
    case 2:
      lcd.clear();
      lcd.print(" LED ON");
      lcd.setCursor(0, 1);
      lcd.print(">LED OFF");
      break;
    
    //de momento los casos item no serán usados
    
    case 3:
      lcd.clear();
      lcd.print(">Item 3");
      lcd.setCursor(0, 1);
      lcd.print(" Item4");
      break;
    case 4:
      lcd.clear();
      lcd.print(" Item3");
      lcd.setCursor(0, 1);
      lcd.print(">Item 4");
      break;
    case 5:
      menu = 4;
      break;
  }
}


//ejecución según el caso

void execute() {
  switch (menu) {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    case 3:
      action3();
      break;
    case 4:
      action4();
      break;
  }
}


//esto es lo que va a desplegarse en pantalla

void action1() {
  lcd.clear();
  lcd.print(">LED");    //aquí también me hubiera gustado 
  delay(150);           //saltar renglón por estética,
  lcd.print("P");   //pero me marcó un error.           
  delay(150);     //se incluirá en el siguiente reporte     
  lcd.print("R");       //de avance de proyecto
  delay(150);
  lcd.print("E");
  delay(150);
  lcd.print("N");
  delay(150);
  lcd.print("D");
  delay(150);
  lcd.print("I");
  delay(150);
  lcd.print("D");
  delay(150);
  lcd.print("O");
  delay(150);
  lcd.print(".");
  
  digitalWrite(LED, HIGH);
  
  delay(500);
}

void action2() {
  lcd.clear();
  lcd.print(">LED"); //aquí me hubiera gustado realizar un salto 
  delay(150);     //de línea para que la palabra apagado se     
  lcd.print("A");       //desplegara en el segundo renglón
  delay(150);
  lcd.print("P");
  delay(150);
  lcd.print("A");
   lcd.print("G");
  delay(150);
  lcd.print("A");
  delay(150);
   lcd.print("D");
  delay(150);
  lcd.print("O");
  delay(150);
  
  digitalWrite(LED, LOW);
  
  delay(500);
}

//la acción 3 se encuentra inhabilitada
//a la espera de que se le indique como realizar una rutina
void action3() {
  lcd.clear();
  lcd.print(">Action: #3");
  
  delay(1500);
}

//de la misma manera la acción 4 de momento no ejecuta 
//rutina o acción alguna, se encuentra vacía como un caso más
void action4() {
  lcd.clear();
  lcd.print(">Action: #4");
  
  delay(1500);
}
