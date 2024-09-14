/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <erwann.lagouche@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:54:21 by elagouch          #+#    #+#             */
/*   Updated: 2024/09/14 13:25:25 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int	main(void)
{
	printf ("%d\n", my_atoi("1234"));
	printf ("%d\n", my_atoi("   1234   "));
	printf ("%d\n", my_atoi("-4321   "));
	printf ("%d\n", my_atoi("   --1337   "));
	printf ("%d\n", my_atoi("---   69420   "));
	printf ("%d\n", my_atoi(""));
	printf ("%d\n", my_atoi("-0"));
	printf ("%d\n", my_atoi(" 354 65465465"));
	printf ("%d\n", my_atoi("[][42][69][]"));
}
