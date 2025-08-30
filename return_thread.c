#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void *rollDice(){
    int *res;
    *res=(rand()%6+1);
    return (void*)res;
}
int main()
{
    srand(time(NULL));
    int *res;
    pthread_t th;
    if(pthread_create(&th,NULL,&rollDice,NULL)!=0){
        return 1;
    }
    if(pthread_join(th,(void**)&res)!=0){
        return 2;
    }
    printf("%d",*res);
    return 0;
}
