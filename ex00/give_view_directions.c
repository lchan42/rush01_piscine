/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_view_directions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:50:05 by mkaploun          #+#    #+#             */
/*   Updated: 2021/09/19 19:53:08 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	give_view_up(int tab[4][4], int col)
{
	int	height;
	int	row;
	int	view;

	height = 0;
	view = 0;
	row = 0;
	if (tab[row][col] == 0)
		return (0);
	while (row < 4)
	{
		if (height < tab[row][col])
		{
			view++;
			height = tab[row][col];
		}
		row++;
	}
	return (view);
}

int	give_view_down(int tab[4][4], int col)
{
	int	height;
	int	row;
	int	view;

	height = 0;
	view = 0;
	row = 3;
	if (tab[row][col] == 0)
		return (0);
	while (row >= 0)
	{
		if (height < tab[row][col])
		{
			view++;
			height = tab[row][col];
		}
		row--;
	}
	return (view);
}

int	give_view_left(int tab[4][4], int row)
{
	int	height;
	int	col;
	int	view;

	height = 0;
	view = 0;
	col = 0;
	if (tab[row][col] == 0)
		return (0);
	while (col < 4)
	{
		if (height < tab[row][col])
		{
			view++;
			height = tab[row][col];
		}
		col++;
	}
	return (view);
}

int	give_view_right(int tab[4][4], int row)
{
	int	height;
	int	col;
	int	view;

	height = 0;
	view = 0;
	col = 3;
	if (tab[row][col] == 0)
		return (0);
	while (col >= 0)
	{
		if (height < tab[row][col])
		{
			view++;
			height = tab[row][col];
		}
		col--;
	}
	return (view);
}
