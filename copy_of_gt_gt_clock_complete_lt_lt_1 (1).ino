#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);  // connections of the display inputs

int mls=0, sec=0, temp, hora=0, pis; 
int min=0, a=0, ano=17, mode, dia=1; 
int mes=1, eoq, up, down ,diaS, soma, e;

void setup(){
  lcd.begin(16,2); //Display 16 characters per 2 lines.
  lcd.clear();     //Clean display.
  pinMode(10,INPUT);  //Increases
  pinMode(11,INPUT);  //Decreases
  attachInterrupt(digitalPinToInterrupt(2), chan, RISING);  
}
void loop(){
  int sensor = analogRead(A1);
  float voltage = sensor * 5.04;
  voltage /= 1023;
  int temp = (voltage - 0.5) * 100;
  lcd.setCursor(11, 1);  //Selects character 11 and line 1.
  lcd.print(temp);       //Prints the temperature.
  lcd.print("\xB0");     
  lcd.print("C");
  
  if(mode == 1) dia=est(dia, 1, 0); 
  if(mode == 2) mes=est(mes, 4, 0); 
  if(mode == 3) ano=est(ano, 7, 0); 
  if(mode == 4) hora=est(hora, 1, 1);
  if(mode == 5) min=est(min, 4, 1);
  if(mode == 6) sec=est(sec, 7, 1);
  
  mls=mls+500;
  if(mls==1000){  //Seconds
    mls=0;  
    sec++;    
  }
  if(sec > 59){  //Minutes
    sec=0;
    min++;
  }
  if(min > 59){  //Hour
    sec=0;
    min=0;
    hora++;
  }
  if(min < 0){
    sec=0;
    min=59;
    hora--;
  }
  if(hora > 23){ //Day
 
    sec=0;
    min=0;
    hora=0;
    dia++;
    diaS++;
  }
  if(hora < 0){ //Back day of the week             
    hora=23;
    min=59;
    dia--;
    diaS--;
  }
  if(mes != 2 && (mes%2) == 1){		//months with 30 or 31 days and February
    if(dia == 32){
      dia=1;
      mes++;
    }
    if(dia < 1){
      dia = 31;
      mes--;
    }
  }
  if(mes!=2 && (mes%2) == 0){
    if(dia > 31){
      dia=1;
      mes++;
    }
  	if(dia < 1){
      dia = 30;
      mes--;
    }
  }
  if(mes == 2){                  
    if(dia > 28){
      dia=1;
      mes=3;
    }
  }
  if(mes == 3){                 
    if(dia < 1){
      dia=28;
      mes=2;
    }
  }
  if(mes == 13){
    mes=1;
    ano++;
  }
  if(mes < 1){
    mes=12;
    ano--;
  }
  if(mes == 9 || mes == 11){
    if(dia > 30){
      dia=1;
      mes++;
    }
  	if(dia == 0){
      dia = 30;
      mes--;
    }
  }

  if(ano == 17) e=-1;
  if(ano == 18) e=0;
  if(ano == 19) e=1;
  if(ano == 20) e=2;
    if(mes == 1 || mes == 10){
      soma = dia+1+e;
        if(soma < 7) diaS = soma;
        if(soma >= 7 && soma < 14) diaS = soma - 7;
        if(soma >= 14 && soma < 21) diaS = soma - 14;
        if(soma >= 21 && soma < 27) diaS = soma - 21;
        if(soma >= 28 && soma < 35) diaS = soma - 28;
        if(soma >= 35) diaS = soma - 35;
    }
    if(mes == 2 || mes == 3 || mes == 11){
      soma = dia+4+e;
        if(soma < 7) diaS = soma;
        if(soma >= 7 && soma < 14) diaS = soma - 7;
        if(soma >= 14 && soma < 21) diaS = soma - 14;
        if(soma >= 21 && soma < 27) diaS = soma - 21;
        if(soma >= 28 && soma < 35) diaS = soma - 28;
        if(soma >= 35) diaS = soma - 35;
    }
    if(mes == 4 || mes == 7){
      soma = dia+0+e;
        if(soma < 7) diaS = soma;
        if(soma >= 7 && soma < 14) diaS = soma - 7;
        if(soma >= 14 && soma < 21) diaS = soma - 14;
        if(soma >= 21 && soma < 27) diaS = soma - 21;
        if(soma >= 28 && soma < 35) diaS = soma - 28;
        if(soma >= 35) diaS = soma - 35;
    }
    if(mes == 5){
      soma = dia+2+e;
        if(soma < 7) diaS = soma;
        if(soma >= 7 && soma < 14) diaS = soma - 7;
        if(soma >= 14 && soma < 21) diaS = soma - 14;
        if(soma >= 21 && soma < 27) diaS = soma - 21;
        if(soma >= 28 && soma < 35) diaS = soma - 28;
        if(soma >= 35) diaS = soma - 35;
    }
    if(mes == 6){
      soma = dia+5+e;
        if(soma < 7) diaS = soma;
        if(soma >= 7 && soma < 14) diaS = soma - 7;
        if(soma >= 14 && soma < 21) diaS = soma - 14;
        if(soma >= 21 && soma < 27) diaS = soma - 21;
        if(soma >= 28 && soma < 35) diaS = soma - 28;
        if(soma >= 35) diaS = soma - 35;
    }
    if(mes == 8){
      soma = dia+3+e;
        if(soma < 7) diaS = soma;
        if(soma >= 7 && soma < 14) diaS = soma - 7;
        if(soma >= 14 && soma < 21) diaS = soma - 14;
        if(soma >= 21 && soma < 27) diaS = soma - 21;
        if(soma >= 28 && soma < 35) diaS = soma - 28;
        if(soma >= 35) diaS = soma - 35;
    }
    if(mes == 9 || mes == 12){
      soma = dia+6+e;
        if(soma < 7) diaS = soma;
        if(soma >= 7 && soma < 14) diaS = soma - 7;
        if(soma >= 14 && soma < 21) diaS = soma - 14;
        if(soma >= 21 && soma < 27) diaS = soma - 21;
        if(soma >= 28 && soma < 35) diaS = soma - 28;
        if(soma >= 35) diaS = soma - 35;
    }
    if(diaS == 1){
      lcd.setCursor(11, 0);
      lcd.print("Dom");
    }
    if(diaS == 2){
      lcd.setCursor(11, 0);
      lcd.print("Seg");
    }
    if(diaS == 3){
      lcd.setCursor(11, 0);
      lcd.print("Ter");
    }
    if(diaS == 4){
      lcd.setCursor(11, 0);
      lcd.print("Qua");
    }
    if(diaS == 5){
      lcd.setCursor(11, 0);
      lcd.print("Qui");
    }
    if(diaS == 6){
      lcd.setCursor(11, 0);
      lcd.print("Sex");
    }
    if(diaS == 0){
      lcd.setCursor(11, 0);
      lcd.print("Sab");
    }
  
  lcd.setCursor(1, 0);      //Select character 1 and line 0, where the message will be displayed.
  addzero(dia);             //Prints the value of "day".
  lcd.print("/");		    //Prints the "/" character.
  addzero(mes);             //Prints the value of "mes".
  lcd.print("/");		    //Prints the "/" character.
  addzero(ano);             //Prints the "year" value.
  lcd.setCursor(1, 10);     //Select character 1 and line 10, where the message will be displayed.
  addzero(hora);            //Prints the "hour" value.
  lcd.print(":");		    //Prints the character ":".
  addzero(min);             //Prints the value of "min"
  lcd.print(":");		    //Prints the character ":".
  addzero(sec);
  delay(500);
}
 
  
//advances the mode when the button is pressed.
void chan(){
  mode++;              
  if(mode >= 6){       //houses that can be modified
    mode = 0;
  }
}
//put "0" before the numbers and print.
void addzero(int eoq){
  if(eoq < 10){
    lcd.print("0");
    lcd.print(eoq);
  }
  if(eoq >= 10){
    lcd.print(eoq);
  }
}
//choose what to change and change with the buttons
int est(int pi, int X, int Y){
  
  up=digitalRead(10);
  down=digitalRead(11);
  
  if(up == 1){      //Increases
    pi++;
  }
  if(down == 1){    //Decreases
    pi--;
  }
  lcd.setCursor(X, Y);  //x = 16 characters of the display and y = 2 lines of the display.
  if(pis == 0){ 
  	addzero(pi); 
    delay(200);
  }
  if(pis == 1){
 	lcd.print("..");     //Select how many houses to modify
    delay(200);
  }
  pis=(pis+1)%2;
  return pi;
}