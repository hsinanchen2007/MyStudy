### 解题思路
在这个主要的函数里又调用了两个函数嘿嘿嘿
首先要算出各个数的二进制表达里有多少个1，我就写了一个ZW函数
然后再判断置位是不是素数，调用判断素数的isSushu函数就好
最后遍历L到R中的所有数字并计数。

### 代码

```c
int ZW(int x)//ZW函数表示x的二进制表达中置位的个数
{
	int count = 0;
	while(x/2>0)
	{
		if (x % 2 == 1)
			count++;
		x = x / 2;
	}
	count++;
	return count;
}
int isSushu(int a)//isSushu函数判断a是不是质数
{
	if (a == 2)
		return 1;
	if (a == 1)
		return 0;
	for (int i = 2; i*i<=a; i++)
	{
		if (a % i == 0)
			return 0;
	}
	return 1;
}
int countPrimeSetBits(int L, int R)
{
	int x,count=0;
	for (int a = L; a <= R; a++)
	{
		x = ZW(a);
		if (isSushu(x))
			count++;
	}
	return count;
}
```