/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_views.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 20:01:10 by mkaploun          #+#    #+#             */
/*   Updated: 2021/09/19 20:01:28 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	give_view_up(int tab[4][4], int col);

int	give_view_down(int tab[4][4], int col);

int	give_view_left(int tab[4][4], int row);

int	give_view_right(int tab[4][4], int row);

int	*give_view_cols(int test[16], int tab[4][4])
{
	int	col;

	col = 0;
	while (col < 4)
	{
		test[col] = give_view_up(tab, col);
		col++;
	}
	col = 3;
	while (col >= 0)
	{
		test[col + 4] = give_view_down(tab, col);
		col--;
	}
	return (test);
}

int	*give_views(int tab[4][4])
{
	int			row;
	static int	test[16];

	give_view_cols(test, tab);
	row = 0;
	while (row < 4)
	{
		test[row + 8] = give_view_left(tab, row);
		row++;
	}
	row = 3;
	while (row >= 0)
	{
		test[row + 12] = give_view_right(tab, row);
		row--;
	}
	return (test);
}

int	full_row(int tab[4][4], int row)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (tab[row][i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	full_col(int tab[4][4], int col)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (tab[i][col] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	view_valid(int tab[4][4], int *entry)
{
	int	i;
	int	*views;

	i = 0;
	views = give_views(tab);
	while (i < 8)
	{
		if (!(full_col(tab, i % 4)) && views[i] > entry[i])
			return (0);
		else if (full_col(tab, i % 4) && views[i] != entry[i])
			return (0);
		i++;
	}
	while (i < 16)
	{
		if (!(full_row(tab, i % 4)) && views[i] > entry[i])
			return (0);
		else if (full_row(tab, i % 4) && views[i] != entry[i])
			return (0);
		i++;
	}
	return (1);
}
