#include<unistd.h>
int main()
{
	
	while (1)
	{
		system("sysctl -a | grep tempe >> readings.txt");
		sleep(15);
	}
	return 0;
}
