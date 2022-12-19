#  超级丑数
编写一段程序来查找第 n 个超级丑数。

超级丑数是指其所有质因数都是长度为 k 的质数列表 primes 中的正整数。

示例:

```
输入: n = 12, primes = [2,7,13,19]
输出: 32 
解释: 给定长度为 4 的质数列表 primes = [2,7,13,19]，前 12 个超级丑数序列为：[1,2,4,7,8,13,14,16,19,26,28,32] 。
```

说明:

1 是任何给定 primes 的超级丑数。
 给定 primes 中的数字以升序排列。
0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000 。
第 n 个超级丑数确保在 32 位有符整数范围内。

<hr>

理解了这一题，再理解这题会方便很多
丑数II：[丑数II解法](https://blog.csdn.net/weixin_39139505/article/details/89454295)
写过此题，那么该题就是对这题的升级解法
##  解：
注：该题是由给出的primes列表构造出后面的丑数。改为用k个指针

数据解释：
primes[]:构造后续丑数的基数
res[]:存放由primes构造的丑数列表
*pos[]:存放指向res的指针数组


```
class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		int k = primes.size();
		int *res = new int[n];
		res[0] = 1;
		int **pos=new int *[k];
		for (int i = 0; i < k; i++)//初始化指针数组
		{
			pos[i] = res;
		}
		int next = 1;//下一个存放位置
		while (next < n)
		{
			int min1 = INT_MAX;
			for (int i = 0; i < k; i++)//找出下一个该存放的丑数
			{
				min1 = (min1 < (*pos[i] * primes[i])) ? min1:(*pos[i] *primes[i] );
			}
			res[next] = min1;
			//找到指针的位置
			for (int i = 0; i < k; i++)
			{
				while(*pos[i] *primes[i]<=res[next])
				{
					pos[i]++;
				}
			}
			next++;
		}
		return res[n - 1];
	}
};
```

