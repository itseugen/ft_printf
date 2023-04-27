/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eweiberl <eweiberl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:17:21 by eweiberl          #+#    #+#             */
/*   Updated: 2023/04/27 15:09:46 by eweiberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	varhandle(char c, va_list args);
static int	printfunc(const char *str, int ccount, va_list args);
/*
* DONE • %c Prints a single character.
* DONE • %s Prints a string (as defined by the common C convention).
* DONE • %p The void * pointer argument has to be printed in hexadecimal format.
* DONE • %d Prints a decimal (base 10) number.
* DONE • %i Prints an integer in base 10.
* DONE • %u Prints an unsigned decimal (base 10) number.
* DONE • %x Prints a number in hexadecimal (base 16) lowercase format.
* DONE • %X Prints a number in hexadecimal (base 16) uppercase format.
* DONE • %% Prints a percent sign.
*/

int	ft_printf(const char *str, ...)
{
	int		ccount;
	va_list	args;

	va_start(args, str);
	ccount = printfunc(str, 0, args);
	va_end(args);
	return (ccount);
}

static int	printfunc(const char *str, int ccount, va_list args)
{
	size_t	i;
	int		wrtfail;

	i = 0;
	wrtfail = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			wrtfail = varhandle(str[++i], args);
			if (wrtfail == 0 && str[i] != 's')
				wrtfail = write(1, &str[i], 1);
			if (wrtfail < 0)
				return (-1);
			ccount = ccount + wrtfail;
		}
		else
		{
			if (write(1, &str[i], 1) < 0)
				return (-1);
			ccount++;
		}
		i++;
	}
	return (ccount);
}

static int	varhandle(char c, va_list args)
{
	int	ccount;

	ccount = 0;
	if (c == 'c')
		ccount = ft_putchar(va_arg(args, int));
	if (c == 's')
		ccount = ft_putstr(va_arg(args, char *));
	if (c == '%')
		ccount = ft_putchar('%');
	if (c == 'i' || c == 'd')
		ccount = ft_putint(va_arg(args, int));
	if (c == 'x' || c == 'X')
		ccount = ft_puthex((long)va_arg(args, unsigned int), c);
	if (c == 'p')
		ccount = ft_put_ptr(va_arg(args, void *));
	if (c == 'u')
		ccount = ft_putunsigned(va_arg(args, unsigned int));
	return (ccount);
}
