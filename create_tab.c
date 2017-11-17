/*
** create_tab.c for BSQ in /home/dommer_c/rendu/CPE_2015_BSQ
** 
** Made by clement dommerc
** Login   <dommer_c@epitech.net>
** 
** Started on  Wed Dec 16 19:47:54 2015 clement dommerc
** Last update Sun Dec 20 20:19:23 2015 clement dommerc
*/

#include "include/bsq.h"

void	dim_tab(char *map, t_dim *dim)
{
  int	l;
  int	c;
  int	i;

  i = 0;
  l = atoi(map);
  c = 0;
  while (map[i] != '\n')
    i++;
  i++;
  dim->pl = i;
  while (map[i] != '\n')
    {
      c++;
      i++;
    }
  dim->line = l;
  dim->col = c;
}

void	tab_set(int **tab, t_dim *dim, char *map)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  while (map[k] != '\n')
    k++;
  k++;
  while (i < dim->line)
    {
      while (j < dim->col)
	{
	  if (map[k] == '.')
	    tab[i][j] = 1;
	  else if (map[k] == 'o')
	    tab[i][j] = 0;
	  j++;
	  k++;
	}
      k++;
      j = 0;
      i++;
    }
}

int	search_min(int **tab, int i, int j)
{
  int	min;

  min = tab[i][j - 1];
  if (min > tab[i - 1][j - 1])
    min = tab[i - 1][j - 1];
  if (min > tab[i - 1][j])
    min = tab[i - 1][j];
  return (min + 1);
}

void	search_square(int **tab, t_dim *dim, int i, int j)
{
  int	tmp;

  i = 0;
  j = 0;
  tmp = tab[i][j];
  dim->size = tmp;
  dim->x = j - (dim->size - 1);
  dim->y = i - (dim->size - 1);
  while (i < dim->line)
    {
      while (j < dim->col)
        {
          if (tmp < tab[i][j])
            {
              tmp = tab[i][j];
              dim->size = tmp;
              dim->x = j - (dim->size - 1);
              dim->y = i - (dim->size - 1);
            }
          j++;
        }
      j = 0;
      i++;
    }
}

int	**create_tab(char *map, t_dim *dim)
{
  int	**tab;
  int	i;
  int	j;

  tab = NULL;
  tab = mem_tab(tab, dim);
  tab_set(tab, dim, map);
  i = 1;
  j = 1;
  while (i < dim->line)
    {
      while (j < dim->col)
        {
          if (tab[i][j] != 0)
            tab[i][j] = search_min(tab, i, j);
          j++;
        }
      j = 1;
      i++;
    }
  search_square(tab, dim, i, j);
  return (tab);
}
