/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:27:54 by donghank          #+#    #+#             */
/*   Updated: 2024/04/01 09:30:15 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *src)
{
	char	*new_src;
	int		i;

	new_src = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!new_src)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		new_src[i] = src[i];
		i++;
	}
	new_src[i] = '\0';
	return (new_src);
}

int	word_count(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		if (!is_sep(*str, charset))
		{
			count++;
			while (!is_sep(*str, charset) && *str != '\0')
				str++;
		}
		else
			str++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		count;
	char	**strs;
	int		i;

	count = word_count(str, charset);
	strs = (char **)malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (NULL);
	while (*str != '\0')
	{
		i = 0;
		if (!is_sep(*str, charset))
		{
			strs[i++] = ft_strdup(str);
			while (!is_sep(*str, charset) && *str != '\0')
				str++;
		}
		else
			str++;
	}
	strs[i] = 0;
	return (strs);
}
