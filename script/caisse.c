#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double calcul_monnaie(double valeur_a_payer, double montant_paye)
{
	double billet[]={2000, 1000, 500, 200, 100, 50, 25};
	double pieces[]={20, 10, 5, 1, 0.50, 0.20, 0.05};

	double monnaie_a_rendre = montant_paye - valeur_a_payer;
	printf("la monnaie a rendre est : Rs%.2f\n", monnaie_a_rendre);

	printf("Billet a rendre :\n ");
	for(int i = 0; i < sizeof(billet) / sizeof(billet[0]); i++){
		int nbre_billet = monnaie_a_rendre/billet[i];
		if (nbre_billet > 0){
			printf("%d * Rs%.2f\n", nbre_billet, billet[i]);
			monnaie_a_rendre -= nbre_billet*billet[i];
		}
	}

	printf("Pieces a rendre :\n");
	for(int i = 0; i < sizeof(pieces) / sizeof pieces[0]; i++){
		int nbre_pieces = monnaie_a_rendre / pieces[i];
		if (nbre_pieces > 0){
			printf("%d * Rs%.2f\n", nbre_pieces, pieces[i]);
			monnaie_a_rendre -= nbre_pieces * pieces[i];
		}
	}
}

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

	printf("vous avez paye %.2fRs\n ", montant_paye);
	calcul_monnaie(valeur_a_payer, montant_paye);

	return 0;
}
