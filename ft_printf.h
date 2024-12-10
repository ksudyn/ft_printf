/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:25:23 by ksudyn            #+#    #+#             */
/*   Updated: 2024/10/29 19:53:23 by ksudyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_putchar_count(char c, int fd);
int	ft_putstr_count(char *s, int fd);
int	ft_putnbr_combined_count(long long n, int fd, int is_unsigned);
int	ft_putnbr_hex_count(unsigned long long n, int fd, int upcase);
int	ft_printf(char const *s, ...);
int	ft_putaddress_count(void *ptr);

#endif
