### 解题思路

![QQ图片20200407180529.png](https://pic.leetcode-cn.com/c2bcf65ea4c0765f4c452e755e4eac8bb21dced3b54ca73f0045a252616559a6-QQ%E5%9B%BE%E7%89%8720200407180529.png)
借前面大佬的思路优化了一下空间复杂度,
由于状态转移时并不需要所有已经计算的状态,
只需要储存一行的状态即可(似乎还有优化的空间...),
代码如下

### 代码

```cpp
class Solution {
public:
    int minDistance(string wordA, string wordB) {
    size_t Alen = wordA.size(), Blen = wordB.size();
	if(Alen*Blen==0)
	{
		return Alen+Blen;
	}

	int* dp = new int[Blen+1] {0};//保存迭代序列

	int old = 0;//记录未更新过的dp[B-1]
	for (size_t A = 0; A <= Alen; ++A)
	{
		old = dp[0];
		dp[0] = A;//更新 dp[0]
		for (size_t B = 1; B <= Blen; ++B)
		{
			if (!A)
			{
				dp[B] = B;//第一轮,初始化迭代序列为 0 1 2 ...
				continue;
			}

			//更新dp[B] 需要以下信息:
			//更新过的dp[B-1]    dp[B-1] 
			//未更新过的dp[B-1]  old 
			//未更新过的dp[B]    dp[B]
			int temp = dp[B];//储存旧值
			if (wordA[A-1] == wordB[B-1])
			{
				dp[B] = old;
			}
			else
			{
				dp[B] = 1 + min(old, min(dp[B], dp[B-1]));
			}
			old = temp;//更新old
		}
	}
	return dp[Blen];
    }
};
```