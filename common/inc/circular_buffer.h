/*
** circular_buffer.h for myIRC in /home/wilmot_g/Rendu/PSU_2015_myirc/common
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Thu May 19 00:42:04 2016 guillaume wilmot
** Last update Thu May 19 03:21:37 2016 guillaume wilmot
*/

#ifndef CIRCULAR_BUFFER_H_
# define CIRCULAR_BUFFER_H_

# define PACKETSIZE 1024 /* A check, au moins 128 */

typedef struct		s_buff
{
  char			buff[PACKETSIZE * 2 + 1];
  char			cmd[PACKETSIZE + 1];
  unsigned int		start;
  unsigned int		idx;
  int			end;
  int			back;
}			t_buff;

char			*get_cmd_buff(int, t_buff *);

#endif /* !CIRCULAR_BUFFER_H_ */
