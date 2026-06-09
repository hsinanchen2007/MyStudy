### 解题思路
手写思路，C暴力求解
![2.jpg](https://pic.leetcode-cn.com/9be1d11e0ddd96fc0849a2904d06041ed5631cf51cfa146e4acf93ea8d43f401-2.jpg)



### 代码

```c
#define MIN(a, b, c) (a < (b < c ? b :c) ? a : (b < c ? b :c))
//定义宏MIN，可以快速地求出三个数当中的最小值
#include<string.h>

int minDistance(char *word1, char *word2)
{
	
	int length1 = strlen(word1);
	int length2 = strlen(word2);
	
	//这里，用了malloc动态申请内存的方法
	//其实，在新的标准中，也可以写成
	//int dp[length1 + 1][length2 + 1];
	//如果写成了上面这种形式，最下面的free部分是需要去掉的
	//从效率上，采用动态内存申请的效率会低一些
	int **dp = (int **)malloc(sizeof(int *) * (length1 + 1));
	for(int i = 0; i < (length1 + 1); i++)
		dp[i] = (int *)malloc(sizeof(int) * (length2 + 1));
	
	//给数组赋初值
	for(int i = 0; i <= length1; i++)
		dp[i][0] = i;
	for(int j = 0; j <= length2; j++)
		dp[0][j] = j;
	
	//遍历，求出整个数组
	for(int i = 1; i <= length1; i++)
	{
		for(int j = 1; j <= length2; j++)
		{
			if(word1[i - 1] == word2[j - 1])
			dp[i][j] = MIN(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] - 1) + 1;
			else 
				dp[i][j] = MIN(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1;
		}
	}
	
	//最终的结果就是dp[length1][length2]
	int ret = dp[length1][length2];
	
	//释放掉动态申请的内存
	for(int i = 0; i <= length1; i++)
		free(dp[i]);
	free(dp);
	
    return ret;
}
```