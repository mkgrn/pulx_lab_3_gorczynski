#include <pthread.h>
#include <stdio.h>

void* compute_prime (void* arg) {
int candidate = 2;
int n = *((int*) arg);
while (1) {
int factor;
int is_prime = 1;
for (factor = 2; factor < candidate; ++factor)
if (candidate % factor == 0) {
is_prime = 0; //znalezienie liczby pierwszej 
break;
}
if (is_prime) { //zmiana liczby pierwszej 
if (--n == 0)
return (void*) candidate; //znalezienie liczby pierszej 
}
++candidate;
}
return NULL;
}
int main () {
pthread_t thread; //przekazanie zmiennej do wątku
int which_prime;

int prime;
printf("Podaj którą liczbę pierwszą chcesz znaleźć: ");
scanf("%d",&which_prime); 
pthread_create (&thread, NULL, &compute_prime,&which_prime); //tworzenie wątku 
pthread_join (thread, (void*) &prime); //łączenie wątku i przekazanie do wyświetlania wartości 
printf("%d liczbą pierwszą jest %d.\n", which_prime,prime);
 return 0;
}
