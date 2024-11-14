/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriq2 <jhenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:52:53 by jhenriq2          #+#    #+#             */
/*   Updated: 2024/05/07 17:29:07 by jhenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_format(char specifier, va_list ap, long int *n)
{
	if (specifier == 'c')
		print_char(va_arg(ap, int), n);
	else if (specifier == 's')
		print_str(va_arg(ap, char *), n);
	else if (specifier == 'p')
		print_ptr(va_arg(ap, unsigned long int), n);
	else if (specifier == 'd')
		print_nbr(va_arg(ap, int), n);
	else if (specifier == 'i')
		print_nbr(va_arg(ap, int), n);
	else if (specifier == 'u')
		print_nbr(va_arg(ap, unsigned int), n);
	else if (specifier == 'x')
		print_hex(va_arg(ap, unsigned int), 0, n);
	else if (specifier == 'X')
		print_hex(va_arg(ap, unsigned int), 1, n);
	else if (specifier == '%')
		print_char(specifier, n);
}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	long int		n;
	unsigned int	i;

	n = 0;
	i = 0;
	if (format == NULL || format[0] == '\0')
		return (-1);
	va_start(ap, format);
	while (format[i] != 0)
	{
		if (format[i] == '%')
			print_format(format[++i], ap, &n);
		else
			print_char(format[i], &n);
		i++;
	}
	va_end(ap);
	return (n);
}
