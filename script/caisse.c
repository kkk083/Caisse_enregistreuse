#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
	srand(time(0));
	double valeur_a_payer = (double)(rand()% 1000 + 1);

	printf("le montant a payer est : Rs%.2f\n", valeur_a_payer);
	double montant_paye;

	do{
		printf("Entrer le montant que vous souhaitez payer : Rs ");
		scanf("%lf", &montant_paye);
		
		if (montant_paye < valeur_a_payer)
			printf("Erreur! vous n'avez pas entrer le bon montant\n");

	}while (valeur_a_payer > montant_paye);

	printf("vous avez entrer le bon montant qui est de %.2fRs\n ", montant_paye);

	return 0;
}
