/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserefog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:04:13 by sserefog          #+#    #+#             */
/*   Updated: 2022/07/27 16:49:53 by sserefog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	char	temp;

	temp = n + '0';
	write(1, &temp, 1);
}

void	print_out(int *arr, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		ft_putnbr(arr[i]);
		i++;
	}
	if (!(arr[0] == 10 - nb && arr[nb - 1] == 9))
	{
		write(1, ", ", 2);
	}
}

void	ft_increase(int n, int *arr)
{
	int	i;
	int	max;

	i = n - 1;
	max = 9;
	while (arr[i] == max)
	{
		i--;
		max--;
	}
	arr[i] += 1;
	while (i < n)
	{
		arr[i + 1] = arr[i] + 1;
		i++;
	}
}

void	ft_print_combn(int nb)
{
	int	arr[10];
	int	i;

	i = 0;
	while (i < nb)
	{
		arr[i] = i;
		i++;
	}
	print_out(arr, nb);
	while (! (arr[0] == 10 - nb && arr[nb - 1] == 9))
	{
		if (arr[nb - 1] < 9)
		{
			arr[nb - 1] += 1;
		}
		else
		{
			ft_increase(nb, arr);
		}
		print_out(arr, nb);
	}
}
