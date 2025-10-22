#include<stdio.h>

int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF )
	{
		int ret = 0;
		if (n % 2 == 0)
		{
			ret = n/2*(1+n);
		}
		else
		{
			ret = (1+n)/2*n;
		}
		printf("%d\n", ret);
	}
	return 0;
}
