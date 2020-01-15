/*
** EPITECH PROJECT, 2019
** CPool_2019
** File description:
** My_str_to_word_array
*/

#include <stdio.h>
#include <stdlib.h>
#include "./include/my.h"

int is_letter(char c) {
    return ((c > 64 && c < 91) || (c < 123 && c > 96) || (c < 58 && c > 47));
}

int measure(char const *blabla, int place) {
    int a = 0;
    while (is_letter(*(blabla + place))) {
        place = place + 1;
        a = a + 1;
    }
    return (a);
}

int find_next(char const *str, int now)
{
    int next = now;
    while (is_letter(*(str + next)) == 0 && *(str + next) != '\0') {
        next = next + 1;
    }
    return (next);
}

int counting(char const *string)
{   int i = 0;
    int count = 0;
    while (string[i] != '\0') {
        while (is_letter(string[i]) == 0)
            i = i + 1;
        count = count + 1;
        while (is_letter(string[i]) == 1)
            i = i + 1;
    }
    return (count);
}

char **my_str_to_word_array(char const *src)
{
    int j = 0;
    int i = 0;
    int count_words = counting(src);
    int pos = 0;
    int w_len = 0;
    char **words = malloc(sizeof(char *) * (count_words + 1));

    while (j < count_words) {
        pos = find_next(src, i + pos);
        w_len = measure(src, pos);
        words[j] = malloc(sizeof(char) * (w_len + 1));
        i = 0;
        while (i < w_len) {
            words[j][i] = src[i + pos];
            i = i + 1;
        }
        words[j][i + pos] = '\0';
        j = j + 1;
    }
    words[j] = NULL;
    return (words);
}