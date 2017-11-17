/*
** bsq.c for BSQ in /home/dommer_c/rendu/CPE_2015_BSQ
** 
** Made by clement dommerc
** Login   <dommer_c@epitech.net>
** 
** Started on  Mon Dec 14 18:05:08 2015 clement dommerc
** Last update Fri Dec 25 16:19:14 2015 clement dommerc
*/

#include "include/bsq.h"

int	open_map(char *file, char **map)
{
  struct stat	s;
  int		o;
  int		st;
  int		size;
  int		r;

  o = open(file, O_RDONLY);
  if (o == -1)
    return (1);
  st = stat(file, &s);
  if (st == -1)
    return (1);
  size = (int)s.st_size;
  (*map) = mem_map((*map), size);
  r = read(o, (*map), size);
  if (r == -1)
    return (1);
  close (o);
  return (0);
}

void	display_tab(int **tab, t_dim *dim)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < dim->line)
    {
      while (j < dim->col)
        {
          printf("%d ", tab[i][j]);
          j++;
        }
      j = 0;
      printf("\n");
      i++;
    }
  printf("\n");
}

void	display_bsq(t_dim *dim, char* map)
{
  int	i;
  int	j;
  int	k;

  i = -1;
  j = -1;
  k = dim->pl;
  while (++i < dim->line)
    {
      while (++j < dim->col)
        {
	  if ((j >= dim->x && j <= dim->x + dim->size - 1) &&
	      (i >= dim->y && i <= dim->y + dim->size - 1))
	    map[k] = 'x';
	  k++;
        }
      j = -1;
      map[k] = '\n';
      k++;
    }
  write(1, map + dim->pl, ((dim->col + 1) * dim->line));
}

int	main(int ac, char **av)
{
  char		*map;
  t_dim		*dim;
  int		er;
  int		**tab;

  map = NULL;
  dim = NULL;
  dim = mem_dim(dim);
  if (ac == 1 || ac > 2)
    {
      printf("USAGE : [./bsq map_file]\n");
      return (1);
    }
  er = open_map(av[1], &map);
  if (er == 1)
    {
      printf("error fonction systeme : open / stat / read\n");
      printf("USAGE : [./bsq map_file]\n");
      return (1);
    }
  dim_tab(map, dim);
  tab = create_tab(map, dim);
  display_bsq(dim, map);
  free_mem(map, dim, tab);
  return (0);
}
