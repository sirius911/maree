#include "lib.h"
#include <math.h>


int	main(void)
{
	
	int 	heureDebut = 12;
	int		minuteDebut = 05;
	int		heureFin = 18;
	int		minuteFin = 02;
	
	double	hF,hD;
	double 	x,y,hauteurEcran,largeurEcran;

	float 	hauteurDebut = 3.50;
	float	hauteurFin = 1.10;
	float	mareeBasse;	

	float	marnage = 0;

	float   dureeMaree,heureMaree = 0;

	float	douzieme = 0;

	float a[6];
	float b[6];

	int	monte;
	
	ft_putstr("\n   *** Calcul de Maree ***\n\n");
	
	ft_putstr("Entrez l'heure de debut de la maree : ");

	// saisie des heures de début et de fin de la marée
	// saisie des hauteur en début et fin de marée

	printf("\nHeure debut Maree : %02dh%02d \tHauteur Debut de maree : %.2f m\n", heureDebut, minuteDebut, hauteurDebut);
	printf("Heure  Fin  Maree : %02dh%02d \tHauteur  Fin  de maree : %.2f m\n", heureFin, minuteFin, hauteurFin);

	// calcul marnage
	marnage = hauteurFin - hauteurDebut;
	if(hauteurFin > hauteurDebut)
	{
		// la maree monte
		monte = 1;
		mareeBasse = hauteurDebut;

	} else
	{
		// la maree descend
		monte = 0;
		mareeBasse = hauteurFin;
	}

	// calcul durée heure marée

	// TODO Verifier que les heures début-fin sont dans le bon sens ou qu'il n'y a pas de changement de jour
	dureeMaree = (heureFin * 60 + minuteFin) - (heureDebut * 60 + minuteDebut);
	heureMaree = dureeMaree / 6;
	
	largeurEcran = (double) dureeMaree +1;
	hauteurEcran = largeurEcran;
	printf("largeur en x : %0.lfmn\n",largeurEcran );
	printf("hauteur en y : %0.lfmn\n",hauteurEcran );

	// calcul du douzieme
	douzieme = marnage / 12;

	printf("La maree ");

	if(monte)
			printf("monte ");
	else
			printf("descend ");
	printf("de %.2f m\n", marnage );

	printf("La durée de 1h maree est de %.1f minutes soit %.4f h \n", heureMaree,(heureMaree/60));

	printf("Douzieme = %.3f m\n", douzieme);

	/*pour chaque f(h) = ah + b
		a = nDz avec n € {1,2,3} suivant la règle des douzième
		1° heure 1dz
		2° heure 2dz
		3° heure 3dz
		4° heure 3dz
		5° heure 2dz
		6° heure 1dz

		b € {b0,b2,...b5}
		b0 = hauteur début de marée
		b1 = b1 + 1Dz
		b2 = b2 + 2Dz
		b3 = b3 + 3Dz
		b4 = b4 + 3Dz
		b5 = b5 + 2Dz
		
	*/
	a[0] = douzieme;
	a[1] = 2 * douzieme;
	a[2] = 3 * douzieme;
	a[3] = 3 * douzieme;
	a[4] = 2 * douzieme;
	a[5] = douzieme;

	b[0] = hauteurDebut;
	b[1] = hauteurDebut + douzieme;
	b[2] = hauteurDebut + (3 * douzieme);
	b[3] = hauteurDebut + (6 * douzieme);
	b[4] = hauteurDebut + (9 * douzieme);
	b[5] = hauteurDebut + (11 * douzieme);

	ft_putstr("On incremente h de heureDebut a heureFin d'1 minute: \n");
	printf("soit de %02dh%02d à %02dh%02d \n", heureDebut,minuteDebut,heureFin,minuteFin);

	hF = (heureFin * 60) + minuteFin;
	hD = (heureDebut * 60) + minuteDebut;
	int h,m,hc,t0;

	h = heureDebut;		// heure de Calcul
	m = minuteDebut;	// minute de calcul
	x=0;

	printf("__h__\tPeriode\t     ax + b\tHauteur\t\tX\tY\n");
	printf("%02dh%02d \t-\t Début de marée\t%.2fm\t\t0\t0\n",heureDebut,minuteDebut,hauteurDebut);
	m++;
	hc = (heureDebut * 60) + minuteDebut;	// temps minute incrémenté
	int periodeCourante = 0;
	t0 = hD;
	int periodeEnCours = 0;
	float hauteurEau;

	while (hc < hF){

		printf("%02dh%02d ",h,m );

		periodeCourante = periodeMaree(hc,hD,heureMaree);
		if(periodeCourante != periodeEnCours){
			// changement de période
			periodeEnCours = periodeCourante;
			t0 = hc;
			printf("\t%dC \t", periodeCourante);

		} else {
			printf("\t%d \t", periodeCourante);

		}
		
		// fonction
		printf("%.2fx + %.2f",a[periodeCourante],b[periodeCourante] );

		// calcul de la hauteur d'eau
		hauteurEau = ((a[periodeCourante]*(hc-t0)/60)+b[periodeCourante] );
		printf("\t%.2fm",hauteurEau);

		x = (hc - ((heureDebut * 60) + minuteDebut))+1;
		printf("\t\t%0.lf", x);

		y = hauteurEcran - ((hauteurEau - mareeBasse) * hauteurEcran / fabs(marnage));
		printf("\t%0.lf\n", y);

		// on incrémente
		hc++;
		m++;
		if(m == 60){
			h++;
			m = 0;
		}
	}
	printf("%02dh%02d ",h,m );
	
	printf("\t- ");
	
	printf("\tFin de marée\t%.2fm\t\t%0.lf\t%0.lf\n",hauteurFin,largeurEcran,hauteurEcran );

	printf("\n\nAu revoir !");
	return (0);
}

int periodeMaree(int h, double heureDebut, float heureMaree){
	
	return (int) ((h - heureDebut) / heureMaree);
}

