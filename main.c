/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafavier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 08:19:40 by cafavier          #+#    #+#             */
/*   Updated: 2024/09/14 08:40:49 by cafavier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putchar.c"
//#include "rush02.c"

void	rush(int x, int y);

int	main(void)
{
	rush(123, 42);
	return (0);
}

void	rush(int x, int y)
{
	int	i;
	int	line;
	int	col;

	i = 0;
	line = 0;
	while (i < (x * y))
	{
		col = i % x;
		line = i / x;
		// Si c'est la PREMIERE OU DERNIERE LIGNE
		if (line == 0 || line == y - 1)
		{
			// Si c'est un COIN de la PREMIERE ligne
			if (line == 0 && (col == 0 || col == x - 1))
			{
				ft_putchar ('A');
			}
			// Si c'est un COIN de la DERNIERE ligne
			else if (line == y - 1 && (col == 0 || col == x - 1))
			{
				ft_putchar ('C');
			}
			else
			{
				ft_putchar ('B');
			}
		}
		else
		{
			// Si c'est la PREMIERE OU DERNIERE COLONNE
			if (col == 0 || col == x - 1)
			{
				ft_putchar ('B');
			}
			else
			{
				ft_putchar (' ');
			}
		}
		// Si c'est LA FIN DE LA LIGNE
		if (col >= x - 1)
		{
			ft_putchar ('\n');
		}
		i++;
	}
}
