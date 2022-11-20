# Pratica11_PDS1

Problema

Você recebeu um arquivo cartelas.txt contendo 1 milhão de apostas feitas na mega-sena. Neste exercício, você deve verificar duas coisas. Primeiro, conte e imprima o número de cartelas que foram vencedoras. Os números sorteados foram: 6, 9, 22, 23, 48, 52. Depois, à título de curiosidade, você deve contar quantas pessoas apostaram nos números do seriado Lost, que são: 4, 8, 15, 16, 23, 42.

    Teoria

    Para abrir um arquivo, você deve usar o comando fopen da linguagem C. Exemplo:

    FILE *arq;
    arq = fopen("cartelas.txt", "r");

A variável arq, que é um ponteiro para FILE, recebe da função fopen o endereço de memória que aponta para a região da memória em que as informações do arquivo cartelas.txt são armazenadas. Ou seja, a partir da variável arq, você pode agora ler dados do arquivo cartelas.txt.

Para ler dados numéricos de um arquivo que você já abriu a partir da função fopen, você deve usar o comando fscanf. Exemplo:

    int n;
    fscanf(arq, "%d", &n);

Note que a função fscanf é muito parecida com a função scanf. Na verdade, a única diferença entre elas é que, na função fscanf, o primeiro parâmetro é o fluxo de dados (ou arquivo) do qual você quer ler dados. No comando acima, a função fscanf leu um inteiro do arquivo arq e o armazenou na variável n.

À cada chamada da função fscanf, novos dados do arquivo serão lidos. Veja o código abaixo:

    while(feof(arq) == 0) {
    	fscanf(arq, "%d", &n);
	    printf("\nli: %d", n);
    }

Neste exemplo, a função feof verifica se ainda existem dados para serem lidos do arquivo arq, ou seja, se ainda não é fim de arquivo. Caso seja fim de arquivo, a função feof retorna 1. Caso ainda existam dados para serem lidos, a função retorna 0. Assim, o código anterior lê um inteiro do arquivo e o imprime enquanto houver dados para serem lidos. Quando for fim de arquivo, a função feof retorna 0 e o while é encerrado.

Por fim, depois que você leu todos os dados relevantes do arquivo, você deve fechá-lo e desalocar a memória dedicada à ele. Para isso, use a função fclose, como no exemplo abaixo:

    fclose(arq);
    
DICA: Para resolver o exercício desta prática, sugiro que comecem devagar. Primeiro, tentem ler e exibir na tela todos os números contidos no arquivo. Depois tentem armazenar os seis números de uma cartela em um vetor de inteiros, para que você possa comparar com a combinação vencedora. Quando for fazer a comparação, sugiro antes ordenar os números da cartela, pois sem isso você terá que testar todas as combinações possíveis. Na aula de 
“Passagem de Parâmetros” uma função que executa algoritmo de ordenação selection sort é descrita.

Gabarito: há apenas uma cartela vencedora, mas há 6 cartelas que apostaram os números do seriado Lost.

DESAFIO PARA OS FORTES

Além dos vencedores, imprimir também o número de cartelas que conseguiram a quadra (acertar quatro números) e a quina (acertar cinco números).
