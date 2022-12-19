### 解题思路
判断返回值为True还是False，看A的个数和L连续出现最多的次数就可以确定。
调用两个函数，numsOfA用来计算A的个数，LisTrue用来看最多连续出现的L是否不超过两个
其实还有一种更简单的方法，就是看是否存在一个i，使得s[i]==s[i+1]&&s[i+1]==s[i+2]。

### 代码

```c
bool checkRecord(char * s){
    if (numsOfA(s) <= 1 && LisTrue(s)==1)
		return 1;
	else
		return 0;
}
int numsOfA(char* s)
{
	int count = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == 'A')
			count++;
	}
    return count;
}
int LisTrue(char* s)
{
	int max=0, flag1=0, i = 0,count=0;
	for (i; s[i] != '\0'; i++)
	{
		if (s[i] == 'L')
		{
			flag1 = 1;
			count++;
			if (max < count)
				max = count;
		}
		else
			flag1 = 0;
		if (flag1 == 0)
			count = 0;
	}
	if (max > 2)
		return 0;
	else
		return 1;
}
```