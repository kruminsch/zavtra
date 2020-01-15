#include "my.h"

int count_words(char **words)
{
    int i = 0;

    while (words[i])
        ++i;
    return (i);
}

int int_compar(const void *first, const void *second)
{
    return (*(int *)first - *(int *)second);
}

int find_biggest(void *array, size_t n_elem, size_t size,\
int compar(const void *, const void *))
{
    int i = 0;
    void *biggest = malloc(size);
    int place = 0;

    slow_memcpy(biggest, array, size);
    while (i < n_elem) {
        if (compar(biggest, array + (size*i)) < 0) {
            slow_memcpy(biggest, (array + (size*i)), size);
            place = i;
        }
        i = i + 1;
    }
    return (place);
}

void swap(void *first, void *second, size_t size)
{
    void *temp;

    temp = malloc(size);
    slow_memcpy(temp, second, size);
    slow_memcpy(second, first, size);
    slow_memcpy(first, temp, size);
}

void my_sorter(void *array, size_t n_elem, size_t size, \
int (*compar)(const void *, const void *))
{
    int i = 0;
    int place;

    while (n_elem) {
        place = find_biggest(array, n_elem, size, compar);
        swap(array+size*place, array+ size * (n_elem-1) , size);
        --n_elem;
    }
}
//ft. gets int numbers as command line args error handling is NOT supported
//if there is only one argument it supposed to be a sentence written in 1 case))
//non_alphanumerical characters separate words
int main(int ac, char **av)
{
    int i = 0;
    int *massiv;
    char **words;
    int n_elem;
    
    if (ac == 2 &&  av[1][0] == '-' && av[1][1] == 'h') {
        write(1, "Program gets integers to sort as command line arguments\n", 56);
        write(1, "error handling is not supported\n", 32);
        write(1, "If there is only one argument is is supposed\n to be a word sentence written in one case\n", 88);
        write(1, "non_alphanumerical characters separate words\n", 45);
        return ('*');
    }
    if (ac < 2) {
        write(2, "what do u want to sort???\n", 26);
        write(2, "please, try with -h\n", 20);
        return ('*');
    }    
    else if (ac == 2) {
        words = my_str_to_word_array(av[1]);
        n_elem = count_words(words);
        my_sorter(words, n_elem, sizeof(char *), my_strcmp);
        print_2_d(words);
        return (0);
    } else {
        massiv = malloc(sizeof(int) * (ac-1) + 1);
        while (i < ac-1) {
            massiv[i] = atoi(av[i+1]);
            i = i + 1;
        }
        my_sorter(massiv, ac - 1, sizeof(int), int_compar);
        for (int i = 0; i < ac - 1; i = i + 1)
            printf("%d\n", massiv[i]);
        return (0);
    }
}