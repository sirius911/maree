#ifndef LIB_H
# define LIB_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int	ft_tolower(int c);
void	ft_putnbr(int nbr);
void	ft_putchar(const char c);
void	ft_putstr(const char *str);
int	ft_strlen(char *str);
int	ft_strcmp(char *s1, char *s2);
char 	*ft_strcpy(char *str, char *str2);
void 	clean(const char *buffer, FILE *fp);
int		periodeMaree(int h,double heureDebut, float heureMaree);
#endif
