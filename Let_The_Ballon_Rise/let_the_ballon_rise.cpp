#include<stdio.h>
#include<iostream>
#include<map>
#include<string>

int main()
{
	int N = 0;
	while (scanf("%d", &N));
	{
		std::map<std::string, int> ballonMap;
		int max = 0;
		std::string name;
		for (int i = 0; i < N; i++)
		{
        	int size = 10240;
        	char* buf = (char *)malloc(size);
			fgets(buf, size, stdin);
			std::string str = buf;
			//std::cout << "name: " << str << std::endl;
			if (ballonMap.count(str) != 0)
			{
				int tmp = ballonMap[str] + 1;
				ballonMap[str] = tmp;
			}
			else
			{
				ballonMap[str] = 1;
			}
			if (max < ballonMap[str])
			{
				max = ballonMap[str];
				name = str;
			}
		}
		std::cout << name << std::endl;
	}
}
