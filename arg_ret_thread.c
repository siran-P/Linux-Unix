#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
int arr[10]={9,8,7,6,5,4,3,2,1,0};
void *get(void *arg){
    int res=*(int*)arg;
  //  printf("%d ",arr[res]);
    int *a=malloc(sizeof(int));
    *a=arr[res];
    free(arg);
    return a;
}
int main()
{
    int res;
    pthread_t th[10];
    for(res=0;res<10;res++){
        int *a=malloc(sizeof(int));
        *a=res;
    if(pthread_create(&th[res],NULL,&get,a)!=0){
        return 1;
    }
    }
    printf("\n");
    for(res=0;res<10;res++){
        int *a;
    if(pthread_join(th[res],(void**)&a)!=0){
        return 2;
    }
    printf("%d ",*a);
    free(a);
    }
    return 0;
}
