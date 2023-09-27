#include <Servo.h>

Servo a1; // Variável Servo
Servo a2; // Variável Servo
Servo a3; // Variável Servo

Servo b1; // Variável Servo
Servo b2; // Variável Servo
Servo b3; // Variável Servo

Servo c1; // Variável Servo
Servo c2; // Variável Servo
Servo c3; // Variável Servo

Servo d1; // Variável Servo
Servo d2; // Variável Servo
Servo d3; // Variável Servo

int pos; // Posição Servo


void setup()
{
 
  
  a1.attach(2);
  a2.attach(3);
  a3.attach(4);
  
  b1.attach(5);
  b2.attach(6);
  b3.attach(7);
  
  c1.attach(8);
  c2.attach(9);
  c3.attach(10);
  
  d1.attach(11);
  d2.attach(12);
  d3.attach(13);
  
  Serial.begin(9600);
  delay(1000);
  
  a1.write(90); // Inicia motor posição zero
  a2.write(135); // Inicia motor posição zero
  a3.write(135); // Inicia motor posição zero
  
  b1.write(90); // Inicia motor posição zero
  b2.write(45); // Inicia motor posição zero
  b3.write(45); // Inicia motor posição zero
  
  c1.write(90); // Inicia motor posição zero
  c2.write(135); // Inicia motor posição zero
  c3.write(135); // Inicia motor posição zero
  
  d1.write(90); // Inicia motor posição zero
  d2.write(45); // Inicia motor posição zero
  d3.write(45); // Inicia motor posição zero
  
}

/**
 * Função que lê uma string da Serial
 * e retorna-a
 */
String leStringSerial(){
  String conteudo = "";
  char caractere;
  
  // Enquanto receber algo pela serial
  while(Serial.available() > 0) {
    // Lê byte da serial
    caractere = Serial.read();
    // Ignora caractere de quebra de linha
    if ((caractere != '\n') &&(isAlphaNumeric(caractere))) {
      // Concatena valores
      conteudo.concat(caractere);
    }
    // Aguarda buffer serial ler próximo caractere
    delay(10);
  }
  Serial.print("Recebido:");
  Serial.println(conteudo);
  return conteudo;
}
  
void loop() {
  String recebido="";
  // Se receber algo pela serial
  if (Serial.available() > 0){
    // Lê toda string recebida
    recebido = leStringSerial();
  }
  
  if (recebido =="F"){avanca(100);} //avanca aranha
  if (recebido =="T"){retorna(100);} //retorna aranha
  if (recebido =="E"){giraEsq(100);} // gira a esquerda
  if (recebido =="D"){giraDir(100);} // gira a esquerda


  //Verifica código de movimento para articulações indenpendentes
  if ((recebido !="F") && (recebido!="T") && (recebido !="E") && (recebido !="D") && (recebido!="P")){
    char pata;
    int art;
    int angulo;

   
    pata = recebido[0]; // Identifica pata a movimentar
    art=recebido[1]-'0'; // Identifica articulação a movimentar
    angulo=(recebido[2]-'0')*100 +(recebido[3]-'0')*10 +(recebido[4]-'0'); // define o angulo da articulação
    
    Serial.print("Pata:");
    Serial.println(pata);
    Serial.print("Articulacao:");
    Serial.println(art);
    Serial.print("Angulo:");
    Serial.println(angulo);
    ControleServo(pata,art,angulo);
  }
  
  recebido="";
  
}

void ControleServo(char pata, int art, int angulo){
  
  // Identifica pata a movimentar
  switch(pata){
    case 'a':
      // Identifica articulação a movimentar
      switch(art){
        case 1:
          a1.write(angulo);// define o angulo da articulação
        break;
        case 2:
          a2.write(angulo);// define o angulo da articulação
        break;
        case 3:
          a3.write(angulo);// define o angulo da articulação
        break;
      }
    break;
    
    case 'b':
      switch(art){
        case 1:
          b1.write(angulo);
        break;
        case 2:
          b2.write(angulo);
        break;
        case 3:
          b3.write(angulo);
        break;
      }
    break;
    
    case 'c':
      switch(art){
        case 1:
          c1.write(angulo);
        break;
        case 2:
          c2.write(angulo);
        break;
        case 3:
          c3.write(angulo);
        break;
      }
    break;
    
    case 'd':
      switch(art){
        case 1:
          d1.write(angulo);
        break;
        case 2:
          d2.write(angulo);
        break;
        case 3:
          d3.write(angulo);
        break;
      }
    break;
  }
}


void avanca(int tempo){
  //Movimento pata A
 
  a1.write(90); 
  a2.write(180); //Sobe Cotovelo 
  a3.write(135); 

  
  delay(tempo);

  a1.write(45); //Avança Onbro
  a2.write(180);
  a3.write(135);

  
  
  delay(tempo);

  a1.write(45); 
  a2.write(130); //Baixa cotovelo
  a3.write(135);

  
  delay(tempo);

  a1.write(90); //posição Repouso
  a2.write(135);//posição Repouso
  a3.write(135);//posição Repouso

  
  delay(tempo);

//Movimento Pata C
  c1.write(90); 
  c2.write(180); 
  c3.write(135);
  
  delay(tempo);
  
  c1.write(135); 
  c2.write(180); 
  c3.write(135);

  delay(tempo);
  
  c1.write(135); 
  c2.write(130); 
  c3.write(135);

  delay(tempo);
  
  c1.write(90); 
  c2.write(135); 
  c3.write(135);

  delay(tempo);

  //Movimento Pata B

  b1.write(90); 
  b2.write(0); 
  b3.write(45);

  delay(tempo);

  b1.write(135);
  b2.write(0);
  b3.write(45);

  delay(tempo);

  b1.write(135);
  b2.write(75); 
  b3.write(45); 
  
  delay(tempo);

  b1.write(90); 
  b2.write(60); 
  b3.write(45); 

  delay(tempo);

  //Movimento Pata D

  d1.write(90); 
  d2.write(0); 
  d3.write(45);
  
  delay(tempo);
  
  d1.write(45); 
  d2.write(0); 
  d3.write(45);

  delay(tempo);
  
  d1.write(45); 
  d2.write(75); 
  d3.write(45);

  delay(tempo);
  
  d1.write(90); 
  d2.write(60); 
  d3.write(45);
  
  delay(tempo);
  
}

void retorna(int tempo){
  //Movimento pata A
 
  a1.write(90); 
  a2.write(180); //Sobe Cotovelo 
  a3.write(135); 

  
  delay(tempo);

  a1.write(135); //Retorna Onbro
  a2.write(180);
  a3.write(135);

  
  
  delay(tempo);

  a1.write(135); 
  a2.write(130); //Baixa cotovelo
  a3.write(135);

  
  delay(tempo);

  a1.write(90); //posição Repouso
  a2.write(135);//posição Repouso
  a3.write(135);//posição Repouso

  
  delay(tempo);

//Movimento Pata C
  c1.write(90); 
  c2.write(180); //Sobe Cotovelo 
  c3.write(135);
  
  delay(tempo);
  
  c1.write(45); //Retorna Onbr
  c2.write(180); 
  c3.write(135);

  delay(tempo);
  
  c1.write(45); 
  c2.write(130); //Baixa cotovelo
  c3.write(135);

  delay(tempo);
  
  c1.write(90); //posição Repouso
  c2.write(135); //posição Repouso
  c3.write(135);//posição Repouso

  delay(tempo);

  //Movimento Pata B

  b1.write(90); 
  b2.write(0); //Sobe Cotovelo 
  b3.write(45);

  delay(tempo);

  b1.write(45);//Retorna Onbro
  b2.write(0);
  b3.write(45);

  delay(tempo);

  b1.write(45);
  b2.write(75); //Baixa cotovelo
  b3.write(45); 
  
  delay(tempo);

  b1.write(90); //posição Repouso
  b2.write(50); //posição Repouso
  b3.write(45); //posição Repouso

  delay(tempo);

  //Movimento Pata D

  d1.write(90);
  d2.write(0);  //Sobe Cotovelo
  d3.write(45);
  
  delay(tempo);
  
  d1.write(135); //Retorna Onbro
  d2.write(0); 
  d3.write(45);

  delay(tempo);
  
  d1.write(135); 
  d2.write(75); //Baixa cotovelo
  d3.write(45);

  delay(tempo);
  
  d1.write(90); //posição Repouso
  d2.write(50); //posição Repouso
  d3.write(45); //posição Repouso
  
  delay(tempo);
  
}

void giraEsq(int tempo){
  //Movimento pata A
 
  a1.write(90); 
  a2.write(180); //Sobe Cotovelo 
  a3.write(135); 

  c1.write(90); 
  c2.write(180);//Sobe Cotovelo  
  c3.write(135);
  
  delay(tempo);

  a1.write(45); //Avança Onbro
  a2.write(180);
  a3.write(135);

  c1.write(45); //retorna Onbro
  c2.write(180); 
  c3.write(135);
  
  
  delay(tempo);

  a1.write(45); 
  a2.write(130); //Baixa cotovelo
  a3.write(135);

  
  c1.write(45); 
  c2.write(130); //Baixa cotovelo
  c3.write(135);
  
  delay(tempo);

  a1.write(90); //posição Repouso
  a2.write(135);//posição Repouso
  a3.write(135);//posição Repouso

  c1.write(90); //posição Repouso
  c2.write(135); //posição Repouso
  c3.write(135);//posição Repouso
  
  delay(tempo);
}

void giraDir(int tempo){
  //Movimento Pata B

  b1.write(90); 
  b2.write(0); //Sobe Cotovelo 
  b3.write(45);

  d1.write(90); 
  d2.write(0); //Sobe Cotovelo 
  d3.write(45);
  
  delay(tempo);

  b1.write(135);//Avança Onbro
  b2.write(0);
  b3.write(45);

  d1.write(135); //Retorna Onbro
  d2.write(0); 
  d3.write(45);
  delay(tempo);

  b1.write(135);
  b2.write(75); //Baixa cotovelo
  b3.write(45); 

  d1.write(135); 
  d2.write(75); //Baixa cotovelo
  d3.write(45);
  
  delay(tempo);

  b1.write(90); //posição Repouso
  b2.write(60); //posição Repouso
  b3.write(45); //posição Repouso

  d1.write(90); //posição Repouso
  d2.write(60); //posição Repouso
  d3.write(45);//posição Repouso
  delay(tempo);

}

void danca(){
//Posição parado
  a1.write(90); // Inicia motor posição zero
  a2.write(135); // Inicia motor posição zero
  a3.write(135); // Inicia motor posição zero
  
  b1.write(90); // Inicia motor posição zero
  b2.write(45); // Inicia motor posição zero
  b3.write(45); // Inicia motor posição zero
  
  c1.write(90); // Inicia motor posição zero
  c2.write(135); // Inicia motor posição zero
  c3.write(135); // Inicia motor posição zero
  
  d1.write(90); // Inicia motor posição zero
  d2.write(45); // Inicia motor posição zero
  d3.write(45); // Inicia motor posição zero

  delay(3000);

//Movimento de conta tempo
  int conta=0;

  while (conta<5){
    a1.write(20); //avança ombro
    a2.write(135); // Inicia motor posição zero
    a3.write(0); // Inicia motor posição zero
    delay(500);

    a1.write(20); //avança ombro
    a2.write(90); // Inicia motor posição zero
    a3.write(0); // Inicia motor posição zero
    delay(500);
    conta++;
    
  }
  
  //movimento Sobe e desce

  conta=0;

  while (conta<5){
    a1.write(90); 
    a2.write(135);
    a3.write(135);
  
    b1.write(90); 
    b2.write(45); 
    b3.write(45); 
  
    c1.write(90); 
    c2.write(135);
    c3.write(135); 
  
    d1.write(90); 
    d2.write(45); 
    d3.write(45); 

    delay(500);

    a1.write(90); 
    a2.write(45);
    a3.write(0);
  
    b1.write(90); 
    b2.write(135); 
    b3.write(180); 
  
    c1.write(90); 
    c2.write(45);
    c3.write(0); 
  
    d1.write(90); 
    d2.write(135); 
    d3.write(180); 
    delay(500); 

    conta++;
  }

  a1.write(90); 
  a2.write(135);
  a3.write(135);
  
  b1.write(90); 
  b2.write(45); 
  b3.write(45); 
  
  c1.write(90); 
  c2.write(135);
  c3.write(135);
  
  d1.write(90); 
  d2.write(45); 
  d3.write(45); 

  delay(1000);

  avanca(500);

  //Movimento de não
  c1.write(90); 
  c2.write(135);  
  c3.write(135);
  conta=0;

  while (conta<5){
    a1.write(20); //avança ombro
    a2.write(135); 
    a3.write(0); 
    delay(500);

    a1.write(90); //avança ombro
    a2.write(135); // Inicia motor posição zero
    a3.write(0); // Inicia motor posição zero
    delay(500);
    conta++;
    
  }
  a1.write(90); 
  a2.write(135);
  a3.write(135);
  
}
