#include "my.h"

int my_strlen(char const *str)
{
    int n = 0;

    while (*(str + n))
        ++n;
    return (n);
}

void print_2_d(char **words)
{
    int i = 0;

    while (words [i]) {
        printf("%s\n", words[i]);
        i = i + 1;
    }
}

void *slow_memcpy(void *dest, const void *src, size_t n)
{
    char *dest_bytes = (char *)dest;
    const char *src_bytes = (char *)src;

    for (int i = 0; i < n; i = i + 1)
        dest_bytes[i] = src_bytes[i];
    return (dest);
}

int my_strcmp(const void *pervoje, const void *vtoroje)
{

    //mozhno konechno i tak:)))))))))))))))))))->->->->
    //return strcmp(* (char * const *)pervoje, * (char * const *)vtoroje);
    int lenght;
    char *first = (*(char *const *)pervoje);
    char *second = (*(char *const *)vtoroje);
    int i = 0;

    if ((my_strlen(first) - my_strlen(second)) > 0)
        lenght = my_strlen(first);
    else
        lenght = my_strlen(second);
    while (i < lenght) {
        if ((first[i] - second[i]) != 0)
            return (first[i] - second[i]);
        else
            i = i + 1;
    }
    if (first[i] == '\0' && second[i] == '\0')
        return (0);
    else if(first[i] == '\0' && second[i] != '\0')
        return (1);
    else
        return (-1);
}

