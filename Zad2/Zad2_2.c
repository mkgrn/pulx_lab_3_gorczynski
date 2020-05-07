#include <pthread.h>
#include <stdio.h>
struct char_print_parms {
char character;
int count;
};
void* char_print (void* parameters) {
struct char_print_parms* p = (struct char_print_parms*)
parameters;
int i;
for (i = 0; i < p->count; ++i)
fputc (p->character, stderr);
return NULL;
}
int main () {
pthread_t thread1_id;
struct char_print_parms thread1_args;
thread1_args.character = 'x';
thread1_args.count = 10;
pthread_create (&thread1_id, NULL, &char_print,
&thread1_args);
void *result;
pthread_join(thread1_id, &result);
return 0;
}
