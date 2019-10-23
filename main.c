/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 21:27:37 by romarash          #+#    #+#             */
/*   Updated: 2019/10/16 21:37:19 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int    main(int argc, char ** argv)
{
    int        fd;
    int     i = 0;
    char    *line;
    
    if (argc < 2)
    {
        printf("Usage %s <filename>\n", argv[0]);
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        close(fd);
        return (-1);
    }
    while (get_next_line(fd, &line) == 1)
    {
        write(1, line, strlen(line));
        i++;
        printf("%d\n", i);
		free(line);
        line = NULL;
    }
    write(1,line,strlen(line));
    free(line);
    line = NULL;
    return (0);
}
