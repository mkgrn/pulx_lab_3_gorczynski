#include <pthread.h>
#include <stdio.h> 
 
void* print_xs (void* unused) { 
while (1) 
fputc ('x', stderr); 
return NULL; } 
int main () { 
pthread_t thread_id; //przekazanie zmiennej na wątek 
pthread_create (&thread_id, NULL, &print_xs, NULL); //utworzenie wątku przez przypisanie funkcji  print_xs
while (1) 
fputc ('o', stderr); 
return 0; 
} 
/* Nie jest możliwe określenie kiedy zostaną wyświetlone poszczególne znaki */
