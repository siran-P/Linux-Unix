#include <stdio.h>
#include<stdlib.h>
#include<pthread.h>
int x=0;
pthread_mutex_t mutex;
void *fun1(){
    for(int i=0;i<1000000;i++){
        pthread_mutex_lock(&mutex);
        x+=1;
        pthread_mutex_unlock(&mutex); 
    }
}
void *fun2(){
     for(int i=0;i<1000000;i++){
       pthread_mutex_lock(&mutex);
       x+=1;
       pthread_mutex_unlock(&mutex); 
     }
}
int main()
{
    pthread_t t1,t2;
    pthread_mutex_init(&mutex,NULL);
    if(pthread_create(&t1,NULL,fun1,NULL)!=0){
        return 1;
    }
    if(pthread_create(&t2,NULL,fun2,NULL)!=0){
        return 1;
    }
    if(pthread_join(t1,NULL)!=0){
        return 2;
    }
    if(pthread_join(t2,NULL)!=0){
        return 2;
    }
     pthread_mutex_destroy(&mutex);
    int a=0;
    for(int i=0;i<1000000;i++)
      a+=1;
    for(int i=0;i<1000000;i++)
      a+=1;
    printf("threads x=%d \nnormal method a=%d",x,a);  //a=x=2000000
    return 0;
}
