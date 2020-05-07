#include <pthread.h>
#include <stdio.h>
#include <time.h>


struct memoizacja {
    int ktora_liczba[5];
    int jaka_liczba[5];
};

void* compute_prime (void* arg) {
int candidate = 2;
int n = *((int*) arg);
while (1) {
int factor;
int is_prime = 1;
for (factor = 2; factor < candidate; ++factor)
if (candidate % factor == 0) {
is_prime = 0;
break;
}
if (is_prime) {
if (--n == 0)
return (void*) candidate;
}
++candidate;
}
return NULL;
}
int main () {
struct memoizacja memo;
int j;
int n= 0;

while(1){
j=0;
pthread_t thread; //przekazanie zmiennej do wątku
int which_prime;
int prime;
printf("Podaj którą liczbę pierwszą chcesz znaleźć: ");
scanf("%d",&which_prime); 

for (int i = 0; i <= 5; i++)
{
if ( which_prime== memo.ktora_liczba[i])
{
printf("%d liczbą pierwszą jest %d.\n", memo.ktora_liczba[i], memo.jaka_liczba[i]);
j=1;
}
}
if(j == 0){
printf("Podaj którą liczbę pierwszą chcesz znaleźć: ");
scanf("%d",&which_prime); 
clock_t t;
t = clock();
pthread_create (&thread, NULL, &compute_prime,&which_prime); //tworzenie wątku 
pthread_join (thread, (void*) &prime); //łączenie wątku i przekazanie do wyświetlania wartości 
printf("%d liczbą pierwszą jest %d.\n", which_prime,prime);
t = clock() - t; 
double time_taken = ((double)t)/CLOCKS_PER_SEC; // sekundy 
printf("Czas trwania funkcji: %f sekund \n", time_taken);
memo.ktora_liczba[n] = which_prime;
memo.jaka_liczba[n] = prime;
n++;
}
}
 return 0;
}

