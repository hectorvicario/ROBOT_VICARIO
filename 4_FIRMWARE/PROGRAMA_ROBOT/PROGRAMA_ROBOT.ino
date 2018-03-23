#include <NewPing.h>
NewPing pollo(3,4); // Triger=8, Echo=9.
int distancia;
volatile int estado=0;
char dato;
int a=250;
int b=250;
void setup( ) {
  pinMode(2,INPUT);
  attachInterrupt(0,int_pul,RISING); // entrada pin2
  //configuramos E/S digitales del robot
  Serial.begin(9600);
  //MOTOR 1
  pinMode(6,OUTPUT);//MOTOR 1
  pinMode(7,OUTPUT);//MOTOR 1
  //MOTOR 2
  pinMode(8,OUTPUT);//MOTOR 2
  pinMode(9,OUTPUT);//MOTOR 2
}
void loop( ) {
  //modo evitaobstaculos
  while(estado==1){
  Serial.print(estado);
  distancia=pollo.ping_cm();
  while(distancia>=20){
        analogWrite(10,250);
        digitalWrite(6,1);
        digitalWrite(7,0);  
        //MOTOR 2 
        analogWrite(11,250);
        digitalWrite(8,1);
        digitalWrite(9,0);
        delay(20);
        distancia=pollo.ping_cm();
   }
   analogWrite(10,255);
   digitalWrite(6,0);
   digitalWrite(7,1);  
        //MOTOR 2 
   analogWrite(11,250);
   digitalWrite(8,1);
   digitalWrite(9,0);
   delay(400);
   
  }
  //modo teledirigido
  while(estado==0){
    Serial.print(estado);
  if (Serial.available() > 0) {
   dato = Serial.read();
   switch (dato) {
    case ('F'): {    
        //robot movimiento adelante
        //MOTOR 1
        analogWrite(10,250);
        digitalWrite(6,1);
        digitalWrite(7,0);  
        //MOTOR 2 
        analogWrite(11,250);
        digitalWrite(8,1);
        digitalWrite(9,0);
        break;
    }
    case ('B'): {    
       //robot movimiento atrás
       //MOTOR 1
       analogWrite(10,250);
       digitalWrite(6,0);
       digitalWrite(7,1);  
       //MOTOR 2 
       analogWrite(11,250);
       digitalWrite(8,0);
       digitalWrite(9,1);
       break;          
    }
    case ('L'): {       
        //robot movimiento izquierda
        //MOTOR 1
        analogWrite(10,200);
        digitalWrite(6,1);
        digitalWrite(7,0);
        //MOTOR 2
        analogWrite(11,0);
        digitalWrite(8,1);
        digitalWrite(9,0);
        break;
    }    
    case ('R'): {     
        //robot movimiento derecha
        //MOTOR 1
        analogWrite(10,0);
        digitalWrite(6,1);
        digitalWrite(7,0);
       //MOTOR 2
        analogWrite(11,200);
        digitalWrite(8,1);
        digitalWrite(9,0);   
        break;
    }
    case ('X'): {
        //MICHAEL JACKSON 
        //MOTOR 1
        analogWrite(10,a);
        digitalWrite(6,1);
        digitalWrite(7,0);
        //MOTOR 2
        analogWrite(11,b);
        digitalWrite(8,0);
        digitalWrite(9,1); 
        break; 
    }
    case ('Y'): {
        //MICHAEL JACKSON
        //MOTOR 1
        analogWrite(10,a);
        digitalWrite(6,0);
        digitalWrite(7,1);
        //MOTOR 2
        analogWrite(11,b);
        digitalWrite(8,1);
        digitalWrite(9,0);
        break;
    }
    case ('S'): {     
        //paro motores
        //MOTOR 1
        analogWrite(10,0);
        //MOTOR 2
        analogWrite(11,0);
        break;
    }
   }
  }
 }
}

void int_pul ( )
{
 estado=!estado;
 delay(300);
}

 

   

