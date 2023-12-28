#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>

char nomescopia[4][50];
int pontosturno[4][2];
int totalpontos[4];
char classificacao[4][50];
int x, y, aux;
char auxstr[50];

main(){
   setlocale(LC_ALL,"Portuguese"); 
    
    //Input dos times e pontos conquistados
    for(x=0;x<4;x++){
    	
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("Digite o nome do time %d: ",x+1);
		fflush(stdin);
        gets(classificacao[x]);
        strcpy(nomescopia[x], classificacao[x]);
        
        for (y=0;y<2;y++){
        	
            printf("Digite os pontos do %d turno para o %s: ",y+1,classificacao[x]);
		     	do{
			       	scanf("%d", &pontosturno[x][y]);
	                 
	                if(pontosturno[x][y]<0){
	                	
	                	printf("Insira apenas números positivos, (time %s, turno %d) = ",classificacao[x],y+1);
						scanf("%d", &pontosturno[x][y]);
		
					}
			
			      }while(pontosturno[x][y]<0);
			      
           		    totalpontos[x] += pontosturno[x][y];
		}
    }

    // Ordenar os times por total de pontos
    for(x=0;x<3;x++){
        for(y=x+1;y<4;y++){
        	
            if (totalpontos[y]>totalpontos[x]){
            	
                aux = totalpontos[x];
                totalpontos[x] = totalpontos[y];
                totalpontos[y] = aux;

                strcpy(auxstr, classificacao[x]);
                strcpy(classificacao[x], classificacao[y]);
                strcpy(classificacao[y], auxstr);
            }else{
            	if ((pontosturno[y][1]>pontosturno[x][1])&&(totalpontos[y]==totalpontos[x])){
            	
                aux = totalpontos[x];
                totalpontos[x] = totalpontos[y];
                totalpontos[y] = aux;

                strcpy(auxstr, classificacao[x]);
                strcpy(classificacao[x], classificacao[y]);
                strcpy(classificacao[y], auxstr);
                
                }
		    }
			
        }
    }
    
    
    // Mostrar resultados!        
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("PONTUAÇÃO CONQUISTADA POR CADA TIME: \n");
    for (x=0;x<4;x++){
        printf(" Time: %s\n", nomescopia[x]);       
        for (y=0;y<2;y++){
            printf("   %d Turno: %d\n", y+1, pontosturno[x][y]);
        }
    }
    
    // Classificação dos times!
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("CLASSIFICAÇÃO FINAL:\n");
    for (x=0;x<4;x++) {
        printf("%d lugar: %s - Total de Pontos: %d\n",x+1, classificacao[x], totalpontos[x]);
    }
    
    //Output do campeão, vice-campeão e pior time do campeonato 
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("TIME CAMPEÃO: %s\n", classificacao[0]);
    printf("VICE-CAMPEÃO: %s\n", classificacao[1]);
    printf("PIOR TIME DO CAMPEONATO: %s\n", classificacao[3]);
}
