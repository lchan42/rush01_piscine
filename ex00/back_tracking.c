/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:09:52 by rabid             #+#    #+#             */
/*   Updated: 2021/09/19 21:02:15 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_tab(int tab[4][4]);

int		sudoku_valid(int tab[4][4]);

int		view_valid(int tab[4][4], int *entry);

int	is_valid(int tab[4][4], int *entry)
{
	if (!(sudoku_valid(tab)))
		return (0);
	else if (!(view_valid(tab, entry)))
		return (0);
	return (1);
}

int	can_end(int tab[4][4], int *entry)
{
	if (is_valid(tab, entry))
	{
		print_tab(tab);
		return (1);
	}
	return (0);
}

int	fill_tab(int tab[4][4], int *entry, int col, int row)
{
	int	i;

	if (col == 4 && row == 3)
	{
		if (can_end(tab, entry))
			return (1);
	}
	if (col == 4)
	{
		row++;
		col = 0;
	}
	i = 0;
	while (++i <= 4)
	{
		if (is_valid(tab, entry))
		{
			tab[row][col] = i;
			if (fill_tab(tab, entry, col + 1, row))
				return (1);
			tab[row][col] = 0;
		}
	}
	return (0);
}
