/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:29:38 by cberneri          #+#    #+#             */
/*   Updated: 2023/10/23 18:00:02 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdigit(long n, int base, int uppercase)
{
	int			value;
	const char	*chars;

	value = 0;
	if (n < 0)
	{
		value += write(1, "-", 1);
		value += ft_printdigit(-n, base, uppercase);
	}
	else if (n < base)
	{
		if (uppercase)
			chars = "0123456789ABCDEF";
		else
			chars = "0123456789abcdef";
		return (value += write(1, &chars[n], 1));
	}
	else
	{
		value += ft_printdigit(n / base, base, uppercase);
		value += ft_printdigit(n % base, base, uppercase);
	}
	return (value);
}
