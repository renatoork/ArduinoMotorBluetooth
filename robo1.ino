// --- Bibliotecas Auxiliares ---
#include <AFMotor.h>         //Inclui biblioteca AF Motor
#include <SoftwareSerial.h>
  
// --- Seleção dos Motores ---
AF_DCMotor motor1(1); //Seleção do Motor 1
AF_DCMotor motor2(2); //Seleção do Motor 2
 
// --- Mapeamento de Hardware ---
 
// --- Protótipo das Funções Auxiliares ---
void robot_forward(unsigned char v);  //Função movimenta robô frente
void robot_backward(unsigned char v); //Função movimenta robô trás
void robot_left(unsigned char v);     //Função movimenta robô esquerda
void robot_right(unsigned char v);    //Função movimenta robô direita
void robot_stop(unsigned char v);     //Função para para o robô
 
// --- Variáveis Globais ---
unsigned char velocidade = 0x00; //armazena velocidade motores (8 bits)

const char opLiga         = '0';
const char opDesliga      = 'S';
const char opFrente       = 'F';
const char opTras         = 'B';
const char opDireita      = 'R';
const char opEsquerda     = 'L';
const char opFrenteEsquerda = 'G';
const char opFrenteDireita = 'I';


char opcao;

SoftwareSerial MinhaSerial(15,14);
          
// --- Configurações Iniciais ---
void setup()
{
  //A biblioteca configura as entradas e saídas pertinentes...  
  velocidade = 0xFF; //Inicia velocidade no valor máximo
  MinhaSerial.begin(9600);

} //end setup
 
 
// --- Loop Infinito ---
void loop()
{
  if (MinhaSerial.available() > 0) {
    opcao = MinhaSerial.read();
    delay(10); //Delay added to make thing stable
  }
  
   switch (opcao)
   {
     case opDesliga: 
        robot_stop(velocidade);
        break;
     case opFrente:
        robot_forward(velocidade);
        break;
     case opTras:
        robot_backward(velocidade);
        break;
     case opEsquerda:
        robot_left(velocidade);
        break;
     case opDireita:
        robot_right(velocidade);
        break;
     case opFrenteDireita:
        robot_forwardleft(velocidade);
        break;
     case opFrenteEsquerda:
        robot_forwardright(velocidade);
        break;
   }  
 
} //end loop
 
 
// --- Desenvolvimento das Funções Auxiliares ---
 
void robot_forwardright(unsigned char v)
{
     motor1.setSpeed(v);
     motor1.run(FORWARD);
     motor2.setSpeed(v*0.35);
     motor2.run(FORWARD);

} 
 
void robot_forwardleft(unsigned char v)
{
     motor1.setSpeed(v*0.35);
     motor1.run(FORWARD);
     motor2.setSpeed(v);
     motor2.run(FORWARD);

} 

void robot_forward(unsigned char v)
{
     motor1.setSpeed(v);
     motor1.run(FORWARD);
     motor2.setSpeed(v);
     motor2.run(FORWARD);

} //end robot forward
 
void robot_backward(unsigned char v)
{
     motor1.setSpeed(v);
     motor1.run(BACKWARD);
     motor2.setSpeed(v);
     motor2.run(BACKWARD);
 
} //end robot backward
 
 
void robot_left(unsigned char v)
{
     motor1.setSpeed(v);
     motor1.run(FORWARD);
     motor2.setSpeed(v);
     motor2.run(BACKWARD);
 
} //end robot left
 
 
void robot_right(unsigned char v)
{
     motor1.setSpeed(v);
     motor1.run(BACKWARD);
     motor2.setSpeed(v);
     motor2.run(FORWARD);
 
} //end robot right
 
 
void robot_stop(unsigned char v)
{
     motor1.setSpeed(v);
     motor1.run(RELEASE);
     motor2.setSpeed(v);
     motor2.run(RELEASE);
 
} //end robot stop
