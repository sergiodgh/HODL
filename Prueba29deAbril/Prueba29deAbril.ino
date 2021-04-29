//Prueba 29 de Abril

int display7c[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};

//display 7 segmentos ánodo común
int display7a[10]= {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x18};

//declarando los pines del display
byte a=2;
byte b=3;
byte c=4;
byte d=5;
byte e=6;
byte f=7;
byte g=8;
byte inc=9;    //resistencia pulldown
byte dec=10;   //resistencia pullup
int contador=0;

//aqui se colocan los bits en el puerto de salida
void puerto(int bits,int ini,int fin){
  for(int i=ini;i<=fin;i++)
  {
    digitalWrite(i,bitRead(bits,i-ini));
  }
}

void setup() {
  
  //la salida se asigna a 8 pines digitales
  
  for(int i=a;i<=g;i++){
    pinMode(i,OUTPUT);
  }
  pinMode(inc,INPUT);
  pinMode(dec,INPUT_PULLUP);
}

void loop() {
    if(digitalRead(inc)){
      delay(100);
      while(digitalRead(inc)); 
      delay(100);
      contador++;
    }

    if(!digitalRead(dec)){
      delay(100);
      while(!digitalRead(dec)); 
      delay(100);
      contador--;
    }

    //en caso de pasar de 9 en el incremento
    if(contador>9){
      contador=0;
    }

    //en caso de pasar de 0 en el decremento
    if(contador<0){
      contador=9;
    }
    
    //para mostrar todo en el display
    puerto(display7c[contador],a,g);
}
