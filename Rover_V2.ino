#include <IRremote.h> 

//pines
//motores
#define motorizq 4
#define motorder 5

//ultrasonido
#define trigger 3 
#define echo 2

//ldr
#define LDR1 A0
#define LDR2 A1

//infrarrojo
#define IR1 A2
#define IR2 A3

//ultrasonido
float distancia;
float duracion; 

//ldr
int ldr_1;
int ldr_2;

//infrarrojo
int ir_1;
int ir_2;

int ir;
int ir2 = 0;


int RECV_PIN = 6; //declaramos el pin que recibira la señal 
IRrecv irrecv(RECV_PIN); 
decode_results results; 

void setup() 
{ 
  Serial.begin(9600); 
  
  //motores
  pinMode(motorizq, OUTPUT);
  pinMode(motorder, OUTPUT);

  digitalWrite(motorizq, HIGH);
  //sensor ultrasonico
  pinMode(trigger, OUTPUT); 
  pinMode(echo, INPUT); 
  
  //sensores LDR
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);

  //infrarrojo
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);

  irrecv.enableIRIn(); // Comienza a recibir los datos 
  
} 
  
void loop() 
{
  switch (ir)
  {
    case 0xF720DF: 
                  //ULTRASONIDO
                  ultrasonico();
                  Serial.println("MODO ULTRASONIDO");
                  break;
    
    case 0xF7A05F: 
                  //LDR
                  ldr();
                  Serial.println("MODO LDR");
                  break;
    
    case 0xF7609F: 
                  //INFRARROJO
                  infrarrojo();  
                  Serial.println("MODO INFRARROJO");
                  break;   
  }

 if (irrecv.decode(&results)) 
{ 
  ir = results.value;
  
  Serial.println(results.value, HEX); // imprime el valor en codigo hexadecimal
   irrecv.resume();// Se preparar para recibir el siguiente valor 

}
} 
  

void giroIzq()
{
  digitalWrite(motorder, HIGH); //girar derecha
  digitalWrite(motorizq, LOW); //frenar izquierda
}

void giroDer()
{
  digitalWrite(motorder, LOW); //frenar derecha
  digitalWrite(motorizq, HIGH); //girar izquierda
}

void avanzar()
{
  digitalWrite(motorder, HIGH); //girar derecha
  digitalWrite(motorizq, HIGH); //girar izquierda
}

void ultrasonico()
{ 
  // Enviar pulso de 10µs 
  digitalWrite(trigger, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigger, LOW); 
  
  // Leer duracion del pulso
  duracion = pulseIn(echo, HIGH); 

  distancia = duracion / 58;
  
  Serial.println(duracion);
  
      if (distancia <= 3)
      { 
        giroDer();
      } 
      else 
      { 
        avanzar();
      }  
}

void ldr()
{
   analogWrite(LDR1, ldr_1); //izquierda
   analogWrite(LDR2, ldr_2); //derecha

      if(ldr_1 > ldr_2)
      {
        giroIzq();
      }
      
      else if(ldr_1 < ldr_2)
      {
        giroDer();
      }
      
      else 
      {
        avanzar();
      }
}

void infrarrojo()
{
   analogWrite(IR1, ir_1); //izquierda
   analogWrite(IR2, ir_2); //derecha

      if(ir_1 > ir_2)
      {
        giroIzq();
      }
      
      else if(ir_1 < ir_2)
      {
        giroDer();
      }
      
      else 
      {
        avanzar();
      }
}
