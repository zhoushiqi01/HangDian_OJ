#include<stdio.h>
#include<iostream>
#include<vector>

int getMax(int a, int b)
{
	if (a >= b)
	{
		return a;		
	}
	else
	{
		return b;
	}
}

int main()
{	
	int T;
	while (scanf("%d", &T) != EOF)
	{
		for (int i = 0; i < T; i++)
		{
			int total = 0;
			scanf("%d", &total);
			std::vector<int> vec;
			for (int j = 0; j < total; j++)
			{
				int tmp = 0;
				scanf("%d", &tmp);
				vec.push_back(tmp);
			}

			int maxSum = -10000000;
			int maxStart = 0;
			int maxEnd = 0;
			
			std::vector<int> vMax(total, 0);

			for (int end = 0; end < total; end++)
			{
				if (end == 0)
				{
					vMax[end] = vec[end];
                    if (maxSum < vMax[end])
                    {
                        maxSum = vMax[end];
                        maxEnd = end+1;
                    }
				}
				else 
				{
					vMax[end] = getMax(vMax[end-1]+vec[end], vec[end]);
					if (maxSum < vMax[end])
					{
						maxSum = vMax[end];
						maxEnd = end+1;
					}
				}
			}
	
			int sum = 0;
			for (int start = maxEnd-1; start >= 0; start--)
			{
				sum += vec[start];
				if (sum == maxSum)
				{
					maxStart = start+1;
				}	
			}

			std::cout << "Case " << i+1 << ":" << std::endl;
			std::cout << maxSum << " " << maxStart << " " << maxEnd << std::endl;
		}
	}
}
