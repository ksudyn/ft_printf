/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:53:01 by ksudyn            #+#    #+#             */
/*   Updated: 2024/10/29 19:44:34 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	receive(char chr, va_list args)
{
	int	count;

	count = 0;
	if (chr == '%')
		count += ft_putchar_count('%', 1);
	else if (chr == 'c')
		count += ft_putchar_count(va_arg(args, int), 1);
	else if (chr == 's')
		count += ft_putstr_count(va_arg(args, char *), 1);
	else if (chr == 'd' || chr == 'i')
		count += ft_putnbr_combined_count(va_arg(args, int), 1, 0);
	else if (chr == 'u')
		count += ft_putnbr_combined_count(va_arg(args, unsigned int), 1, 1);
	else if (chr == 'x')
		count += ft_putnbr_hex_count(va_arg(args, unsigned int), 1, 0);
	else if (chr == 'X')
		count += ft_putnbr_hex_count(va_arg(args, unsigned int), 1, 1);
	else if (chr == 'p')
		count += ft_putaddress_count(va_arg(args, void *));
	else
		count += ft_putchar_count(chr, 1);
	return (count);
}

int	ft_printf(char	const *s, ...)
{
	va_list	arg;
	int		s_index;
	int		count;
	int		result;

	va_start(arg, s);
	s_index = 0;
	count = 0;
	while (s[s_index])
	{
		if (s[s_index] == '%')
		{
			s_index++;
			if (!s[s_index])
				break ;
			result = receive(s[s_index], arg);
			if (result == -1)
				return (va_end(arg), -1);
			count += result;
		}
		else
			count += ft_putchar_count(s[s_index], 1);
		s_index++;
	}
	return (va_end(arg), count);
}
/*unsigned#include <stdio.h>

int main() 
{
    int num = 42;
    unsigned int unum = 420;
    char *str = "Hello, world!";
    void *ptr = (void *)str;

    printf("===== Comparación con printf original =====\n");
    
    printf("Char: %c\n", 'A');
    ft_printf("Char: %c\n", 'A');

    printf("String: %s\n", str);
    ft_printf("String: %s\n", str);

    printf("Decimal: %d\n", num);
    ft_printf("Decimal: %d\n", num);

    printf("Unsigned: %u\n", unum);
    ft_printf("Unsigned: %u\n", unum);

    printf("Hex (lowercase): %x\n", unum);
    ft_printf("Hex (lowercase): %x\n", unum);

    printf("Hex (uppercase): %X\n", unum);
    ft_printf("Hex (uppercase): %X\n", unum);

    printf("Pointer: %p\n", ptr);
    ft_printf("Pointer: %p\n", ptr);

    printf("Percentage: %%\n");
    ft_printf("Percentage: %%\n");

    char *null_str = NULL;
    printf("Null String: %s\n", null_str);
    ft_printf("Null String: %s\n", null_str);

    return 0;
}*/
