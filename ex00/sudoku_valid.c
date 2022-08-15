/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:32:29 by rabid             #+#    #+#             */
/*   Updated: 2021/09/19 20:07:24 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid_row(int tab[4][4], int row)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (tab[row][i] == tab[row][j] && tab[row][i] != 0)
				return (0);
			j++;
		}	
		i++;
	}
	return (1);
}

int	valid_col(int tab[4][4], int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (tab[i][col] == tab[j][col] && tab[i][col] != 0)
				return (0);
			j++;
		}	
		i++;
	}
	return (1);
}

int	sudoku_valid(int tab[4][4])
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (row < 4)
	{
		if (!(valid_row(tab, row)))
			return (0);
		row++;
	}
	while (col < 4)
	{
		if (!(valid_col(tab, col)))
			return (0);
		col++;
	}
	return (1);
}
