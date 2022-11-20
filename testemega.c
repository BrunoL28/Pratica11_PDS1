#include <stdio.h>
#include <math.h>

#define MAX_TAM pow(10, 6)

int main(){
	int a, b, c, d, e, f;
	int i = 0;
	FILE *arq;
	arq = fopen("cartelas.txt", "r");
	for(i = 0; i <= MAX_TAM; i++){
		fscanf(arq, "%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
		printf("%d %d %d %d %d %d\n", a, b, c, d, e, f);
	}
	fclose(arq);
	return 0;
}