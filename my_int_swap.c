#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int int_compar(const void *first, const void *second)
{
    return (*(int *)first - *(int *)second);
}

int find_biggest(void *array, size_t n_elem, size_t size, int compar(const void *, const void*))
{
    int i = 0;
    int biggest = *(int *)array;
    int place = 0;

    //CHTOBI BEZ SOHRANENIJA SORT NADO DRUGOJ NORMANLIJ ALGO...(((
    //??????????????????????????????????????????????????????????
    (void) compar;//((((((((((
    while (i < n_elem) {
        if (biggest < *(int *)(array + size*i)) {
            biggest = *(int *)(array + size*i);
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
    memcpy(temp, second, size);
    memcpy(second, first, size);
    memcpy(first, temp, size);
}

void my_sorter(void *array, size_t n_elem, size_t size, int (*compar)(const void *, const void *))
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
int main(int ac, char **av)
{
    int i = 0;    
    int *massiv = malloc(sizeof(int) * ac - 1);
    
    while (i < ac-1) {
        massiv[i] = atoi(av[i+1]);
        i = i + 1;
    }
    my_sorter(massiv, ac - 1, sizeof(int), int_compar);
    for (int i = 0; i < ac - 1; i = i + 1)
       printf("%d\n", massiv[i]);
    return (0);
}