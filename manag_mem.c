/*
** manag_mem.c for BSQ in /home/dommer_c/rendu/CPE_2015_BSQ
** 
** Made by clement dommerc
** Login   <dommer_c@epitech.net>
** 
** Started on  Wed Dec 16 18:06:46 2015 clement dommerc
** Last update Sun Dec 20 19:25:23 2015 clement dommerc
*/

#include "include/bsq.h"

t_dim	*mem_dim(t_dim *dim)
{
  dim = malloc(sizeof(t_dim));
  if (dim != NULL)
    {
      dim->line = 0;
      dim->col = 0;
      dim->x = 0;
      dim->y = 0;
      dim->size = 0;
      dim->pl = 0;
    }
  return (dim);
}

char	*mem_map(char *map, int size)
{
  int	i;

  i = 0;
  map = malloc(sizeof(char) * size + 1);
  if (map == NULL)
    exit(1);
  while (i < size + 1)
    {
      map[i] = 0;
      i++;
    }
  return (map);
}

int	**mem_tab(int **tab, t_dim *dim)
{
  int	i;

  i = 0;
  tab = malloc(sizeof(int *) * dim->line);
  if (tab == NULL)
    exit(1);
  while (i < dim->line)
    {
      tab[i] = malloc(sizeof(int) * dim->col);
      if (tab == NULL)
	exit(1);
      i++;
    }
  return (tab);
}

void	free_mem(char *map, t_dim *dim, int **tab)
{
  int	i;

  i = 0;
  while (i < dim->line)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
  free(dim);
  free(map);
}
