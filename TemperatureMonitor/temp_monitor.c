#include<string.h>
#include<unistd.h>
#include<stdio.h>

int main( int argc,char *args[]){

	char exec[100];

	system("/usr/local/bin/bash ./FreqLevels.sh");
	
	
	strcpy(exec,"/usr/local/bin/bash ./FrequencyScale.sh");

	//strcat(exec,args[1]);

	sleep(2);

	int pid=fork();
	if (pid)
	{
		while(1)
		{
			system(exec);
			
			sleep(15);
		}
	}
	else
	{
		while(1)
		{
			system("/usr/local/bin/bash ./WakeUp.sh");
			
			sleep(1);			
		}
	}

	return 0;	
	

}
