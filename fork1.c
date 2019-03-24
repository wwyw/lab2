#include <unistd.h>
#include <stdio.h>
#include<sys/types.h> 

int main()
{
    pid_t pid1;
    printf("P1为父进程，PID为%d\n",getpid());
    pid1 = fork();
    if(pid1<0)
    {
        printf("创建失败\n");
        return 0;
    }
    else if(pid1 == 0)
    {
        printf("P3是子进程,PID为%d\n",getpid());
        return 0;
    }
    else
    {
	pid_t pid2;
        pid2 = fork();
        if(pid2<0)
        {
            printf("创建失败\n");
            return 0;
        }
        else if(pid2 == 0)
        {
            printf("P2是子进程,PID为%d\n",getpid());
	    pid_t pid3;
            pid3 = fork();
            if(pid3<0)
            {
                printf("创建失败\n");
                return 0;
            }  
            else if(pid3 == 0)
            {
                printf("P4是子进程，PID为%d\n",getpid());
                return 0;
            }
	    sleep(1);
	    pid_t pid4;
            pid4 = fork();
	    if(pid4<0)
            {
                printf("创建失败\n");
                return 0;
            }
	    else if(pid4 == 0)
            {
                printf("P5是子进程，PID为%d\n",getpid());
                return 0;
            }
        }
    }
    return 0;
}
