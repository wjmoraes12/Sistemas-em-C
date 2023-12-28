#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

char operador, resposta[3];
float numero1, numero2;

main(){
  setlocale(LC_ALL,"Portuguese");
  
  do{
         printf("Calculadora em C\n");
         printf("Operações disponíveis: +, -, *, /, % %\n");
         printf("Escreva em uma única linha (1 + 1)\n");
         
         scanf("%f",&numero1);
         scanf("%s",&operador);
         scanf("%f",&numero2);
		 
		switch(operador){
			
			case '+':
                printf("O resultado da SOMA: %.2f\n\n", numero1+numero2);
                break;
                

            case '-':
                printf("O resultado da SUBTRAÇÃO: %.2f\n\n", numero1-numero2);
                break;
                

            case '*':
                printf("O resultado da MULTIPLIÇÃO: %.2f\n\n", numero1*numero2);
                break;
                

            case '/':
            	
                if(numero2 != 0)
                    printf("O resultado da DIVISÃO: %.2f\n\n", numero1/numero2);
                else
                    printf("Não existe divisão por 0, insira o divisor novamente:\n");
                    scanf("%f",&numero2);
                    printf("O resultado da DIVISÃO: %.2f\n\n", numero1/numero2);
                break;
                

            case '%':
            	printf("%d\n\n", (int)numero1%(int)numero2);
                break;

		}  
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");  
		
		printf("Deseja continuar calculando: sim ou nao\n");
		scanf("%s",resposta);
			
    }while(strcmp(resposta,"sim")==0);
}

