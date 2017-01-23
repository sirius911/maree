#include "lib.h"

int	main(void)
{
	
	int 	heureDebut = 12;
	int		minuteDebut = 05;
	int		heureFin = 18;
	int		minuteFin = 02;

	float 	hauteurDebut = 3.50;
	float	hauteurFin = 1.10;	

	float	marnage = 0;

	float   dureeMaree,heureMaree = 0;

	float	douzieme = 0;

	int	monte;
	
	ft_putstr("\n   *** Calcul de Maree ***\n\n");
	
	ft_putstr("Entrez l'heure de debut de la maree : ");

	// saisie des heures de début et de fin de la marée
	// saisie des hauteur en début et fin de marée

	printf("\nHeure debut Maree : %02dh%02d \tHauteur Debut de maree : %.2f m\n", heureDebut, minuteDebut, hauteurDebut);
	printf("Heure  Fin  Maree : %02dh%02d \tHauteur  Fin  de maree : %.2f m\n", heureFin, minuteFin, hauteurFin);

	// calcul marnage
	if(hauteurFin > hauteurDebut)
	{
		// la maree monte
		marnage = hauteurFin - hauteurDebut;
		monte = 1;
	} else
	{
		// la maree descend
		marnage = hauteurDebut - hauteurFin;
		monte = 0;
	}

	// calcul durée heure marée

	// TODO Verifier que les heures début-fin sont dans le bon sens ou qu'il n'y a pas de changement de jour
	dureeMaree = (heureFin * 60 + minuteFin) - (heureDebut * 60 + minuteDebut);
	heureMaree = dureeMaree / 6;
	
	// calcul du douzieme
	douzieme = marnage / 12;

	printf("La maree ");

	if(monte)
			printf("monte ");
	else
			printf("descend ");
	printf("de %.2f m\n", marnage );

	printf("La durée de 1h maree est de %.2f minutes\n", heureMaree);

	printf("Douzieme = %.3f m\n", douzieme);

	printf("\n\nAu revoir !");
	return (0);
}

