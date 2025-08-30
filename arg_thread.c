#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
int arr[10]={9,8,7,6,5,4,3,2,1,0};
void *get(void *arg){
    int res=*(int*)arg;
    printf("%d ",arr[res]);
    free(arg);
}
int main()
{
    srand(time(NULL));
    int res;
    pthread_t th[10];
    for(res=0;res<10;res++){
        int *a=malloc(sizeof(int));
        *a=res;
    if(pthread_create(&th[res],NULL,&get,a)!=0){
        return 1;
    }
    }
    for(res=0;res<10;res++){
    if(pthread_join(th[res],NULL)!=0){
        return 2;
    }
    }
    return 0;
}
