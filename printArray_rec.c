#include <stdio.h>

void printArray(int chisla[], size_t size){
if (size != 0){
 printf("%d\n", chisla[size -1]);
 printArray(chisla, size -1);}
 else printf("TOLKO NAOBOROT");
}

int main (void){
int massiv[] = {3,6,8,5,45,32,109,73,78,12};
size_t size = sizeof(massiv)/sizeof(massiv[0]);

printArray(massiv, size);
return '*';
}
