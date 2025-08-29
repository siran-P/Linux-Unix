#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int x=3;
int main()
{
    int pid=fork();
     if(pid==-1){// if error
         return 1;
     }
    if(pid==0){//child process -> pid=0
        x++;
    }
    sleep(2);
    printf("%d-%d\n",pid,x);
    if(pid!=0){//parent process -> pid=child's pid
        wait(NULL);
    }
    return 0;
}
