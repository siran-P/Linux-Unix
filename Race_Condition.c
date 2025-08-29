#include <stdio.h>
#include<stdlib.h>
#include<pthread.h>
int x=0;
void * fun1(){
    for(int i=0;i<1000000;i++)
      x+=1;
}
void * fun2(){
     for(int i=0;i<1000000;i++){
       x+=1;
     }
}
int main()
{
    pthread_t t1,t2;
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
    int a=10;
    for(int i=0;i<1000000;i++)
      a+=1;
    for(int i=0;i<1000000;i++)
      a+=1;
    printf("threads x=%d \nnormal method a=%d",x,a);  //a=2000010 but x<a because of race condition
    return 0;
}
