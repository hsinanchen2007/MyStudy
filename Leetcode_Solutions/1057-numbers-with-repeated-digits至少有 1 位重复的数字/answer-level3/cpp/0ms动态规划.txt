### 解题思路
用动态规划求不同状态的解。
![image.png](https://pic.leetcode-cn.com/c77c684765ace78ae37218bda4316203cfaf0e2e8f0829fbdea9bd30eba55772-image.png)

### 代码

```cpp
class Solution {
public:
int dp8(bool*access,int log10,int N,bool first,int c)
{
	int firstBit = N / (static_cast<int>(pow(10, log10)));
	int choice = 0;
	if (first)
	{
		for (int i = 1; i < firstBit; i++)
				if (!access[i])choice++;
	}
	else
	{
		if (log10>0)
		{
			for (int i = 0; i < firstBit; i++)
				if (!access[i])choice++;
		}
		else for (int i = 0; i < firstBit + 1; i++)
				if (!access[i])choice++;
	}
	int pro = 1;
	for (int i = 0; i < log10; i++)
		pro *= c - i;
	pro *= choice;
	int res = pro;
	bool ordfirstBit = access[firstBit];
	access[firstBit] = true;
	if(log10>0&&!ordfirstBit)
	res += dp8(access, log10 - 1, N % (static_cast<int>(pow(10, log10))), false, c - 1);
	return res;
}
int Aij(int i, int j)
{
	int pro = 1;
	for (int k = 0; k < j; k++)
		pro *= i - k;
	return pro;
}
    int numDupDigitsAtMostN(int N) {
        if(N<10)
        return 0;
    int log10 = 0;
	for (; pow(10, log10) <= N; log10++);
	log10--;
	log10--;
	int a = 0;
	for (int i = 0; i <= log10; i++)
		a += 9*Aij(9, i);
	bool*access = new bool[10];
	for (int i = 0; i < 10; i++)access[i] = false;
	log10++;
	int b = dp8(access, log10, N, true, 9);
	int res = a + b;
	res = N - res;
	return res;
    }
};
```