#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_words(char **words);
int int_compar(const void *first, const void *second);
int my_strlen(char const *str);
//int my_strcmp(char const *s1, char const *s2);
char **my_str_to_word_array(char const *src);
int my_putstr(char const *str);
void my_putchar(char c);
int find_biggest(void *array, size_t n_elem, size_t size, int compar(const void *,\
                                                                     const void*));
void swap(void *first, void *second, size_t size);
void my_sorter(void *array, size_t n_elem, size_t size, \
int (*compar)(const void *, const void *));
    
void print_2_d(char **words);
void *slow_memcpy(void *dest, const void *src, size_t n);
int my_strcmp(const void *pervoje, const void *vtoroje);

#endif /* !MY_H */
