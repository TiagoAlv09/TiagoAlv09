#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

		char produtos;

	do{
		int qntde;
		float vlrtotalinv = 0;

		printf("Gerenciamento de Inventário de Produtos\n");

		do {
			printf("\nDigite a quantidade de produtos que deseja adicionar ao inventário: ");
			scanf("%d", &qntde);

			if (qntde <= 0){
				printf("ERROR! Quantidade de produtos tem que ser maior que zero.\n");
			}
		}while (qntde <= 0);

		int *qtdeproduto = malloc(qntde * sizeof(int));
		float *precounit = malloc(qntde * sizeof(float));
		float *vlrtotal = malloc(qntde * sizeof(float));

		for (int i = 0; i < qntde; i++){

			do {
				printf("\nDigite a quantidade do %d produto: ", i+1);
				scanf("%d", &qtdeproduto[i]);

				if (qtdeproduto[i] < 0) {
					printf("ERROR! Quantidade do produto tem que ser maior que zero.\n");
				}
			} while (qtdeproduto[i] < 0);

			do {
				printf("Digite o preço unitário do %d produto: ", i+1);
				scanf("%f", &precounit[i]);

				if (precounit[i] <= 0) {
					printf("ERROR! O preço do produto tem que ser maior que zero.\n");
				}
			} while (precounit[i] <= 0);


			vlrtotal[i] = qtdeproduto[i] * precounit[i];

			vlrtotalinv += vlrtotal[i];

		}

		printf("\nLISTA DE PRODUTOS");
		for (int i = 0; i < qntde; i++){
			printf("\nProduto %d	-	Quantidade: %d	-	Preço: %.2f	-	Valor total: %.2f"
					, i + 1, qtdeproduto[i], precounit[i], vlrtotal[i]);
		}

		printf("\n\nValor total do inventário: R$ %.2f\n", vlrtotalinv);

		free(qtdeproduto);
		free(precounit);
		free(vlrtotal);

		printf("\nDeseja adicionar mais produtos? Digite(S – Sim / N – Não): ");
		scanf(" %c", &produtos);

	}while (produtos == 'S' || produtos == 's');

	return 0;
}