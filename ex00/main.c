/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 20:01:36 by mkaploun          #+#    #+#             */
/*   Updated: 2021/09/19 21:01:11 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		fill_tab(int tab[4][4], int *entry, int col, int row);

void	ft_putchar(char c);

void	print_tab(int tab[4][4]);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

int	entry_validity(char *entry_str)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(entry_str);
	if (len != 31)
		return (0);
	while (i < len)
	{
		if (!(entry_str[i] >= '1' && entry_str[i] <= '4'))
			return (0);
		i++;
		if (!(entry_str[i] == ' ') && !(entry_str[i] == '\0'))
			return (0);
		i++;
	}
	return (1);
}

void	parse_entry(char *entry_str, int entry[])
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(entry_str);
	while (j < len)
	{
		entry[i] = entry_str[j] - 48;
		i++;
		j++;
		j++;
	}
}

void	fill_zeros(int tab[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	entry[16];
	int	tab[4][4];

	fill_zeros(tab);
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else if (entry_validity(argv[1]))
		parse_entry(argv[1], entry);
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (fill_tab(tab, entry, 0, 0))
	{
		return (0);
	}
	else
	{
		write(1, "Error\n", 6);
	}
}
