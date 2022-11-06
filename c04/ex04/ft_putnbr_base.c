/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserefog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 20:00:27 by sserefog          #+#    #+#             */
/*   Updated: 2022/08/08 20:00:34 by sserefog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] < 32 || base[i] > 126)
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nb, char *base)
{
	int	i;
	int	nb_base;

	i = 0;
	nb_base = 0;
	if (check_base(base) == 1)
	{
		while (base[i] != '\0')
		{
		i++;
		}
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -1 * nb;
		}
		if (nb >= i)
		{
			ft_putnbr_base(nb / i, base);
		}
		nb_base = nb % i;
		ft_putchar(base[nb_base]);
	}
}
