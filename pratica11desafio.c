#include <stdio.h>
#include <math.h>

#define MAX_TAM 2 * pow(10, 9)

void ordenaVetor(int vetor[], int n){
	int i, j;
	int menor, count, aux;
	do{
		menor = MAX_TAM;
		for(i = j; i < n; i++){
			if(vetor[i] < menor){
				menor = vetor[i];
				count = i;
			}
		}
		aux = vetor[j];
		vetor[j] = vetor[count];
		vetor[count] = aux;
		j++;
	}while(j < n);
}

int main(){
	int i, count;
	int quina = 0, quadra = 0;
	int id_cartela = 1;
	int sorteio[6];
	int big_win[6] = {6, 9, 22, 23, 48, 52};
	int seriado_lost[6] = {4, 8, 15, 16, 23, 42};
	FILE *arq, *compara;
	arq = fopen("cartelas.txt", "r");
	compara = fopen("compara.txt", "w");
	while(feof(arq) == 0){
		fprintf(compara, "\nCartela ordenada: ");
		for(i = 0; i < 6; i++)
			fscanf(arq, "%d ", &sorteio[i]);
		ordenaVetor(sorteio, 6);
		for(i = 0; i < 6; i++)
			fprintf(compara, "%d ", sorteio[i]);
		fprintf(compara, "\n");
		for(count = 0; count < 6; count++)
			if(sorteio[count] != seriado_lost[count])
				break;
		if(count == 5)
				quina++;
		for(count = 0; count < 6; count++)
			if(sorteio[count] != seriado_lost[count])
				break;
		if(count == 4)
				quadra++;
		id_cartela++;
		}
		printf("\nUm total de %d pessoas acertou a quina.\n", quina);
		printf("\nUm total de %d pessoas acertou a quadra.\n", quadra);
	fclose(arq);
	fclose(compara);
	return 0;
}