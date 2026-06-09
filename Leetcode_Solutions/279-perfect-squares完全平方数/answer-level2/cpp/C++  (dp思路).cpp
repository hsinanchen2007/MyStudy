### 解题思路

![BD1K`C\[QZ47_BZUN`6N8MX0.png](https://pic.leetcode-cn.com/015e71c53e42ec9824f2904a04aefa5121148ec49566ef3878be34e4a95a4ae0-BD1K%60C%5BQZ47_BZUN%606N8MX0.png)

+ dp[i]的含义，值i最少需要的平方数的个数,dp[0] = 0;
+ 对于每一个dp数组中的i，先算j=sqrt(i),因为j*j<=i(j*j为小于等于i的最大平方数).设rs(最终需要的个数，最多需要i个数）= i;
+ 从j到1循环遍历，即，若使用j*j这个数,需要的个数为 1+dp[i-j*j].（即循环的含义就是，是否用j*j来凑i）
+ 每遍历一次，与rs比较一次，最终得到dp[i];

### 代码

```cpp
class Solution {
public:
    int numSquares(int n) {
		vector<int>dp(n+1);
        dp[0] = 0;
        for(int i=1;i<=n;i++)
		{
            int rs = i;
			for(int j=sqrt(i);i-j*j>=0&&j>0;j--)
			{
				if(dp[i-j*j]+1<rs)
                    rs = dp[i-j*j]+1;
			}
            dp[i] = rs;
		}
		return dp[n];
        
        
    
    }
};
```