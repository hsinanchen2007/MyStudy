### 解题思路
用时100%，内存100%，没看题解，写了一个半小时，本以为是一道简单题，没想到坑还挺多。
首先说思路：我分两了三种情况，分别是长度相等，len1>len2,len2>len1
先求最大公约数，用maxSubString来记录最长字符串
1.如果相等，就用strcmp比较，如果strcmp == 0，就说明两个字符串完全相同，标志一下flag = 3
2.如果len1 > len2,从以len2为标准进行遍历，如有不同，跳出，这时的i是小于len2的，然后再判断长字符串的下一个字符是否是短字符串的第一个字符，主要防止ABCDEF  ABC这种情况，如果是这种情况，用flag = 1标记一下
3.如果len2 < len1同理
最后根据标志flag的情况以及i是否等于短字符串的长度返回相应的字符串

注意：maxSubString要用指针定义，然后申请内存空间，不能直接用maxSubString[1000],因为如果用数组定义，它是一个局部变量，则它再函数结束后会接着释放掉，则主程序接收到的就是NULL，所以需要用指针，虽然指针maxSubString也是局部变量在函数结束后也会消失，但是它可以将地址返回到主程序，主程序就可以通过该地址找到字符串。

### 代码

```c
char* gcdOfStrings(char* str1, char* str2) //str1长  str2短
{
	int i = 0;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int lenFir = len1;
	int lenSec = len2;
	char *maxSubString;
	int gcd, flag = 0;
	int j;

	maxSubString = (char *)malloc(sizeof(char) * 1000);
	memset(maxSubString, 0, 1000);
	gcd = len1 % len2;
	while (gcd != 0)  
	{
		len1 = len2;
		len2 = gcd;
		gcd = len1 % len2;
	}
	if (lenFir > lenSec)
	{
		for (i = 0; i < strlen(str2); i++)
		{
			if (str2[i] != str1[i])
				break;
		}

		if (str1[i] != str2[0])  //比较长字符串的下一个字符是否等于短字符串的第一个字符
		{
			flag = 1;
		}
	}
	else if(lenFir < lenSec)
	{
		for (i = 0; i < strlen(str1); i++)
		{
			if (str1[i] != str2[i])
				break;
		}
		
		if (str1[0] != str2[i])
		{
			flag = 2;
		}
	}
	else if(lenFir = lenSec)
	{
		if (strcmp(str1, str2) == 0)
		{
			flag = 3;
		}
	}

	for (j = 0; j < len2; j++)  //最长字符串 len2是最大公约数
	{
		maxSubString[j] = str2[j];
	}

	if (i==strlen(str2) && flag==0  ||  i==strlen(str1) && flag==0)
	{
		return maxSubString;
    }
	else if (flag == 3)
	{
		return str2;
	}
	else 
	{
		return "";
	}

}
```