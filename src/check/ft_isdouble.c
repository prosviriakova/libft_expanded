/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:27:30 by oprosvir          #+#    #+#             */
/*   Updated: 2024/05/08 22:02:33 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_valid_double_char(char c, bool *has_decimal)
{
	if (ft_isdigit((int)c))
		return (true);
	if (c == '.')
	{
		if (*has_decimal)
			return (false);
		*has_decimal = true;
		return (true);
	}
	return (false);
}

bool	is_double(const char *str)
{
	bool	has_decimal;
	bool	has_digits;

	has_decimal = false;
	has_digits = false;
	while (ft_isspace((int)*str))
    {
		str++;
    }
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (is_valid_double_char(*str, &has_decimal))
			has_digits = true;
		else
			return (false);
		str++;
	}
	return (has_digits && has_decimal);
}
