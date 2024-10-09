/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcebria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:05:13 by arcebria          #+#    #+#             */
/*   Updated: 2024/10/09 16:54:07 by arcebria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	format_analizer(char f, va_list args, int *count)
{
	if (f == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (f == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (f == 'd')
		ft_putchar(va_arg(args, int), count);
	else if (f == 'u')
		ft_putchar(ca_arg(args, int), count);

}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int	i;
	int	count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				ft_putstr(va_arg(args, char *), &count);
			else if (str[i] == 'c')
				ft_putchar(va_arg(args, int), &count);
			else if (str[i] == 'd' || str[i] == 'i')
				ft_putnbr(va_arg(args, int), &count);
			else if (str[i] == 'u')
				ft_putuns(va_arg(args, int), &count);
			i++;
		}
		if (str[i] && str[i] != '%')
		{
			ft_putchar(str[i], &count);
			i++;
		}
	}
	va_end(args);
	return (count);
}

#include <stdio.h>
int	main(void)
{
	ft_printf("Hola %s tienes %d eurillos%cPorfa.", "primo", 10, '?');
	return (0);
}	
