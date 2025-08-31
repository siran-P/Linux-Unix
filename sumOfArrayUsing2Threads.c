#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
int arr[]={10,9,8,7,6,5,4,3,2,1,0,35};
struct arr{
    int *ar;
    int n;
};
void *get(void *arg){
    struct arr res=*(struct arr*)arg;
    int *a=res.ar;
    int sum=0;
    for(int i=0;i<res.n;i++){
        sum+=a[i];
    }
    *(int*)arg=sum;
   // return arg;
}
int main()
{
    int res;
    pthread_t th1,th2;
    int *fs,*ss;
    int n=sizeof(arr)/sizeof(arr[0]);
    struct arr *ex1 = malloc(sizeof(struct arr));
    ex1->ar = arr;
    ex1->n = n / 2;

    struct arr *ex2 = malloc(sizeof(struct arr));
    ex2->ar = arr + (n / 2);
    ex2->n = n / 2;
    if(pthread_create(&th1,NULL,&get,ex1)!=0){
        return 1;
    }
    if(pthread_create(&th2,NULL,&get,ex2)!=0){
        return 1;
    }
    
    if(pthread_join(th1,(void**)&fs)!=0){
        return 2;
    }
    if(pthread_join(th2,(void**)&ss)!=0){
        return 2;
    }
    printf("%d %d %d",*fs,*ss,*fs+*ss);
    free(fs);
    free(ss);
    return 0;
}
