int ft_strlen(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
    int i;
    int j;
    int k;
    char *str;

    i = 0;
    j = 0:
    k = 0;
    str = NULL;
    if (!s1)
    {
        s1 = malloc(sizeof(char));
        s1[0] = '\0';
    }
    k = ft_strlen(s1) + ft_strlen(s2);
    str = malloc(sizeof(char) * (k + 1));
    if (!str)
        return (NULL);
    while (s1)
    {
        str[i] = s1[i];
        i++;
    }
    while (s2)
    {
        str[i] = s2[j];
        i++;
        j++;
    }
    str[i] = '\0';
    free(s1);
    return (str);
}

char *get_line(int fd)
{
    char *line;
    char *buffer;
    int i;

    i = 1;
    line = NULL;
    buffer = NULL;
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    while (i != 0)
    {
        i = read(fd, buffer, BUFFER_SIZE);
        if (i == -1)
        {
            if (buffer)
                free(buffer);
            free (line);
            return (NULL);
        }
        buffer[1] = '\0';
        if (buffer[0] == '\n')
        {
            line = ft_strjoin(line, buffer);
            free(buffer);
            retrun (line);
        }
        line = ft_strjoin(line, buffer);
    }
    free(buffer);
    return (line);
}

char *get_next_line(int fd)
{
    char *result:
    result = NULL;
    if (fd < 0)
        return (NULL);
    result = get_line(fd);
    return (result);
}