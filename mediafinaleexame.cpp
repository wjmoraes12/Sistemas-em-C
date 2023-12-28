#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>


// Vetores e matrizes globais
char disciplinas[3][100];
float mediasBimestrais[3][4];
float totalPontosAno[3];
float notaExame[3];
int x,i;


// Procedimento que faz o input das matérias do curso técnico do usuário
void input() {
    printf("INPUT DAS MATÉRIAS DO CURSO TÉCNICO\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-\n");

    for (x=0; x<3; x++){
    	
        printf("Insira o nome da %d disciplina do seu curso técnico: ", x+1);
        scanf("%s", disciplinas[x]);
        
    }
}


// Procedimento que faz input dos valores das mediasbimestrais
void medias(char x1[], int z) {
    printf("Insira as 4 médias bimestrais de %s:\n", x1);

    for (i=0;i<4;i++){
    		
        do{
            printf("Média do %d bimestre: ", i+1);
            scanf("%f", &mediasBimestrais[z][i]);
            
        }while((mediasBimestrais[z][i]<0)||(mediasBimestrais[z][i]>10));
        
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}


// Função que calcula os pontos totais
float somatorio(int posicao){
    float soma=0;

    for (i=0;i<4;i++){
    	
        soma += mediasBimestrais[posicao][i];
		   
    }
    return soma;
}


// Procedimento que faz o cálculo do exame
void examefinal(float &x1, int x2) {
	
    x1 = 10 - (x1 / 4);
}

main(){
	setlocale(LC_ALL,"Portuguese");
	
    input();
    system("cls"); 
    

    for (x=0;x<3;x++){
    	
        medias(disciplinas[x], x);
    }

    for (x=0;x<3;x++){
    	
        totalPontosAno[x] = somatorio(x);
    }

    printf("OUTPUT DOS VALORES EXIBINDO OS RESULTADOS CONQUISTADOS\n");

    for (x=0;x<3;x++){
    	
        printf("%s - %.2f + %.2f + %.2f + %.2f = %.2f\n", disciplinas[x], mediasBimestrais[x][0],mediasBimestrais[x][1], mediasBimestrais[x][2], mediasBimestrais[x][3], totalPontosAno[x]);
    }
    

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    for (x=0;x<3;x++) {
    	
        if (totalPontosAno[x]>=24) {
        	
            printf("APROVADO EM %s\n", disciplinas[x]);
            
        }else
        	if(totalPontosAno[x]<15){
            
			printf("RETIDO EM %s\n", disciplinas[x]);
			
        	}else{
        		
            printf("EXAME FINAL EM %s\n", disciplinas[x]);
            printf("INSIRA A NOTA OBTIDA NO EXAME EM %s: ", disciplinas[x]);
            scanf("%f", &notaExame[x]);
            examefinal(totalPontosAno[x], x);

	            if (notaExame[x] >= totalPontosAno[x]){	
	            
	                printf("RESULTADO APÓS EXAME: APROVADO em %s\n", disciplinas[x]);
	                
	            }else{
	            	
	                printf("RESULTADO APÓS EXAME: RETIDO em %s\n", disciplinas[x]);
	            }
        	}
        	 printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    }
}
