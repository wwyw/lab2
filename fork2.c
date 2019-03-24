#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
    pid_t pid1,pid2,pid3,pid4;
    int i;
    printf("P1为父进程，PID为%d\n",getpid());
    pid1 = fork();
    if(pid1<0)
    {
        printf("创建失败\n");
        return 0;
    }
    else if(pid1 == 0)
    {
        while(1)
	{
           printf("P3是子进程,PID为%d,父进程为P1,PID为%d\n",getpid(),getppid());
	}
        return 0;
    }
    else
    {
        pid2 = fork();
        if(pid2<0)
        {
            printf("创建失败\n");
            return 0;
        }
        else if(pid2 == 0)
        {
            pid3 = fork();
            if(pid3<0)
            {
                printf("创建失败\n");
                return 0;
            }
            else if(pid3 == 0)
            {
                while(1)
		{
		    printf("P4是子进程,PID为%d,父进程为P2,PID为%d\n",getpid(),getppid());
		}
                return 0;
            }
            pid4 = fork();
            if(pid4<0)
            {
                printf("创建失败\n");
                return 0;
            }
            else if(pid4 == 0)
            {
                while(1)
                {       
                    printf("P5是子进程,PID为%d,父进程为P2,PID为%d\n",getpid(),getppid());
                }
                return 0;
            }
            i=1000;
            while(i-->0)
	    {
		printf("P2是子进程,PID为%d,父进程为P1,PID为%d\n",getpid(),getppid());
                while(i==500)
                {
                    int* p;
		    *p = 1;	
                }

	    }
            int *status;
            waitpid(pid3,status, 0);
            waitpid(pid4,status, 0);
            return 0;
        }
    }
    int *status;
    waitpid(pid2,status, 0);
    waitpid(pid1,status, 0);         
    return 0;
}

