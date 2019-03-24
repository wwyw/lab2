#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t pid=fork();
	if(pid>0)
	{
	    //父进程中执行空循环
	    while(1){}
	}
	else if(!pid)
	{
	    //子进程中调用exec打开vi编辑器
	    int ret;
	    ret=execl("/usr/bin/vi","vi",NULL);
	    if(ret==-1)
		perror("execl");
	}
	else
	{
	    printf("调用失败");
	}
	return 0;
}

