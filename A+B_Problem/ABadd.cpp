#include <stdio.h>
#include <string>
#include <iostream>

std::string Sum(std::string strA, std::string strB)
{
	std::string ret;
	int lenA = strA.size() - 1;
	int lenB = strB.size() - 1;
	int carry = 0;
	while (lenB >= 0)
	{
		int tmpA = strA[lenA] - '0';
		int tmpB = strB[lenB] - '0';
		int tmpC = tmpA + tmpB + carry;
		carry = tmpC / 10;
		int tmpD = tmpC % 10;
		char c = tmpD + '0';
		// std::cout << "tmpA: " << tmpA << " tmpB: " << tmpB 
		//		<< " tmpC: " << tmpC << " tmpD: " << tmpD
		//		<< " carry: " << carry << " c: " << c << std::endl;
		ret.insert(ret.begin(), c);
		lenA--;
		lenB--;
	}

	while (lenA >= 0)
	{
		int tmpA = strA[lenA] - '0';
		int tmpC = tmpA + carry;
		carry = tmpC / 10;
		int tmpD = tmpC % 10;
		char c = tmpD + '0';
		//std::cout << "tmpA: " << tmpA << " tmpC: " << tmpC
		//		<< " tmpD: " << tmpD << " carry: " << carry
		//		<< " c: " << c << std::endl;
		ret.insert(ret.begin(), c);
		lenA--;
	}
	if (carry > 0)
	{
		char c = carry + '0';
		ret.insert(ret.begin(), c);
	}
	return ret;
}

int main()
{
	int T = 0;
	while (scanf("%d", &T) != EOF)
	{
		std::string tmp;
		getline(std::cin, tmp);
		for (int i = 0; i < T; i++)
		{
			std::string strIn;
			std::string strA;
			std::string strB;
			getline(std::cin, strIn);
			//std::cout << "strIn: " << strIn << std::endl;
			for (int j = 0; j < strIn.size(); j++)
			{
				if (strIn[j] == ' ')
				{
					strA = strIn.substr(0, j);
					strB = strIn.substr(j+1);
				}
			}
			std::string ret;
			if (strA.size() >= strB.size())
			{
				ret = Sum(strA, strB);
			}
			else
			{
				ret = Sum(strB, strA);
			}
			std::cout << "Case " << i+1 << ":" << std::endl;
			std::cout << strA << " + " << strB << " = " << ret << std::endl; 	
		}
	}	
}
