#include "lib.h"

int	main(void)
{
	//int	continuer;
	char	rep[20] = "";
	char	heureDebut[10] = "";
	char	heureFin[10] = "";
	//float	hauteurDebut = 0;
	//float	HauteurFin = 0;
	//int	i;
	//int 	grosCaractere = 0;
	//char 	tmp[20]="";
	
	//int nbJoueur;	
	//Joueur *joueurs=NULL;
		
	
	ft_putstr("\n   *** Calcul de Maree ***\n\n");
	
	ft_putstr("Entrez l'heure de debut de la maree : ");

	fgets(rep, sizeof(rep), stdin);
	clean(rep, stdin);
	ft_strcpy(heureDebut,rep);
	ft_putstr("Entrez l'heure de fin de la maree : ");

	fgets(rep, sizeof(rep), stdin);
	clean(rep, stdin);
	ft_strcpy(heureFin,rep);

	printf("\nHeure debut Maree : %s \nHeure   Fin  Maree : %s",heureDebut,heureFin);

	printf("\n\nAu revoir !");
	return (0);
}

