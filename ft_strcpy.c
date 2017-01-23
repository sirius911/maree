#include "lib.h"

char	*ft_strcpy(char *str, char *str2)
{
	int i;
	int y;

	y = 0;
	i = ft_strlen(str2);
	while (i > 0)
	{
		str[y] = str2[y];
		y++;
		i--;
	}
	str[y] = '\0';
	return (str);
}
