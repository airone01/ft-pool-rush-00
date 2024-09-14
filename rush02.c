/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <erwann.lagouche@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:54:59 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/14 14:59:01 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	ft_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	my_atoi(char *str)
{
	int	count;
	int	mult;

	mult = 1;
	count = 0;
	while (!(((*str >= '0') && (*str <= '9')) || (*str == '-')))
		str++;
	while (*str != '\0')
	{
		if (ft_is_numeric(*str))
			count = (count * 10) + (*str - '0');
		else if (*str != '-')
			return (count * mult);
		else if (*str == '-')
		{
			if (mult == 1)
				mult = -1;
			else if (mult == -1)
				mult = 1;
		}
		str++;
	}
	return (count * mult);
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
	int	line;

	col = i % x;
	line = i / x;
	if (line == 0 || line == y - 1)
	{
		if (col == 0 || col == x - 1)
			pt_corner (y, inv_y, line);
		else
			ft_putchar ('B');
	}
	else
	{
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
		pt_line (x, y, inv_y, i);
		if (col >= x - 1)
			ft_putchar ('\n');
		i++;
	}
}
