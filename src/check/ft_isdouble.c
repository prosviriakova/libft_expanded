/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:27:30 by oprosvir          #+#    #+#             */
/*   Updated: 2024/05/08 21:51:09 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		if (ft_isdigit((unsigned char)*str))
			has_digits = true;
		else if (*str == '.')
		{
			if (has_decimal)
				return (false);
			has_decimal = true;
		}
		else
			return (false);
		str++;
	}
	return (has_digits && has_decimal);
}
