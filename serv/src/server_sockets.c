/*
** server_sockets.c for server_sockets in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Wed May 18 18:02:07 2016 Nyrandone Noboud-Inpeng
** Last update Sun May 22 02:02:11 2016 guillaume wilmot
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "serv.h"
#include "errors.h"

int		store_answer(t_list *user, const char *answer, int ret_value)
{
  if (user == NULL)
    return (puterr_int(ERR_UNKNOWNUSER, -1));
  if (write(((t_udata *)(user->struc))->fd, answer, strlen(answer)) == -1)
    return (puterr_int(ERR_ANSWER, -1));
  return (ret_value);
}

t_socket	*init_server_socket(const int port)
{
  t_socket	*socket;
  int		istrue;

  istrue = 1;
  if ((socket = create_socket()) == NULL
      || socket->init(socket, port, "TCP", INADDR_ANY) == -1
      || setsockopt(socket->fd, SOL_SOCKET, SO_REUSEADDR,
		    &istrue, sizeof(int)) == -1
      || socket->bind(socket) == -1
      || socket->listen(socket) == -1)
    return (NULL);
  save_socket(socket, 1);
  return (socket);
}
