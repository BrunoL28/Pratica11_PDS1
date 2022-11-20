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
	int count_cartela_sorteada = 0, count_cartela_lost = 0;
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
			if(sorteio[count] != big_win[count])
				break;
		if(count == 6)
			printf("\nA cartela %d foi sorteada.\n", id_cartela);
		for(count = 0; count < 6; count++)
			if(sorteio[count] != big_win[count])
				break;
		if(count == 6)
			count_cartela_sorteada++;
		for(count = 0; count < 6; count++)
			if(sorteio[count] != seriado_lost[count])
				break;
		if(count == 6)
			printf("\nA cartela %d representa uma aposta dos numeros do seriado Lost.\n", id_cartela);
		for(count = 0; count < 6; count++)
			if(sorteio[count] != seriado_lost[count])
				break;
		if(count == 6)
				count_cartela_lost++;
		id_cartela++;
		}
		printf("\nHouve um total de %d cartelas vencedoras.\n", count_cartela_sorteada);
		printf("\nHouve um total de %d cartelas com a aposta advinda de 'Lost'.\n", count_cartela_lost);
	fclose(arq);
	fclose(compara);
	return 0;
}