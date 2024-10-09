/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_cs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:59:48 by arcebria          #+#    #+#             */
/*   Updated: 2024/10/08 20:51:50 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(int c, int *count)
{
	if (write(1, &c, 1) != 1)
	{
		*count = -1;
		return ;
	}
	(*count)++;
}

void	ft_putstr(char *s, int *count)
{
	int	i;

	if (!s)
	{
		ft_putstr("(null)", count);
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], count);
		i++;
	}
}
