/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriq2 <jhenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:10:34 by jhenriq2          #+#    #+#             */
/*   Updated: 2024/05/16 14:31:05 by jhenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(int c, long int *n)
{
	write(1, &c, 1);
	(*n)++;
}

void	print_str(char *str, long int *n)
{
	if (!str)
	{
		print_str("(null)", n);
		return ;
	}
	while (*str != '\0')
	{
		print_char(*str, n);
		str++;
	}
}

void	print_nbr(long int num, long int *n)
{
	if (num < 0)
	{
		print_char('-', n);
		num = -num;
	}
	if (num > 9)
		print_nbr(num / 10, n);
	print_char(num % 10 + '0', n);
}

void	print_hex(unsigned int num, int up, long int *n)
{
	char	*exchar;

	if (up)
		exchar = "0123456789ABCDEF";
	else
		exchar = "0123456789abcdef";
	if (num >= 16)
		print_hex(num / 16, up, n);
	print_char(exchar[num % 16], n);
}

void	print_ptr(unsigned long int ptr, long int *n)
{
	static int	first = 1;
	char		*exchar;

	if (!ptr)
	{
		print_str("(nil)", n);
		return ;
	}
	if (first)
	{
		print_str("0x", n);
		first = 0;
	}
	exchar = "0123456789abcdef";
	if (ptr >= 16)
		print_ptr(ptr / 16, n);
	print_char(exchar[ptr % 16], n);
	if (ptr < 16)
		first = 1;
}
