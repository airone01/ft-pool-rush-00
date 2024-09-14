/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafavier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 08:19:40 by cafavier          #+#    #+#             */
/*   Updated: 2024/09/14 13:14:11 by cafavier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putchar.c"
//#include "rush02.c"
#include <stdio.h>
#include <limits.h>

void	rush(int x, int y);

int	main(void)
// int	main(int argc, char **argv)
{
	// char	*arg_1;
	// char	*arg_2;
	// int	x;
	// int	y;
	// if (argc < 3)
	// {
	// 	write (1, "Usage: rush <x> <y>", 19);
	// 	return (1);
	// }
	// if (x > 46340 || y > 46340)
	// {
	// 	write (1, "Un de vos arguments est trop grand. Veuillez utiliser des valeurs plus petites.", 77);
	// 	return (1);
	// }
	// arg_1 = argv[1];
	// arg_2 = argv[2];
	// ATOI HERE
	// rush(x, y);
	rush(5, 3);
	return (0);
}

void	pt_corner(int y, int inv_y, int line)
{
	if ((inv_y == 0) && (line == 0))
		ft_putchar ('A');
	else if ((inv_y == 1) && (line == y - 1))
		ft_putchar ('A');
	else if ((inv_y == 0) && (line == y - 1))
		ft_putchar ('C');
	else if ((inv_y == 1) && (line == 0))
		ft_putchar ('C');
}

void	pt_line(int x, int y, int inv_y, int i)
{
	int	col;
	int	inv_z;
	int	line;

	col = i % x;
	line = i / x;
	// Si c'est la PREMIERE OU DERNIERE LIGNE
	if (line == 0 || line == y - 1)
	{
		// Si c'est un coin
		if (col == 0 || col == x - 1)
			pt_corner (y, inv_y, line);
		else
			ft_putchar ('B');
	}
	else
	{
		// Si c'est la PREMIERE OU DERNIERE COLONNE
		if (col == 0 || col == x - 1)
			ft_putchar ('B');
		else
			ft_putchar (' ');
	}
}

void	rush(int x, int y)
{
	int	i;
	int	col;
	int	inv_y;

	inv_y = 0;
	if (x < 0)
		x = -x;
	if (y < 0)
	{
		inv_y = 1;
		y = -y;
	}
	i = 0;
	while (i < (x * y))
	{
		col = i % x;
	//	line = i / x;
		pt_line (x, y, inv_y, i);
		if (col >= x - 1)
			ft_putchar ('\n');
		i++;
	}
}
