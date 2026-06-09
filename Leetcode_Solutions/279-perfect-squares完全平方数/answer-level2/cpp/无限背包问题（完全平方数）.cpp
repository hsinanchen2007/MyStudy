### 解题思路
动态规划里面的无限背包问题，一维dp；
dp[i]表示i为多少个完全平方数的和；那么首先需要初始化的是1~sqrt(n)的dp为1；
然后状态转移方程为 dp[i] = min(dp[i], dp[i-k1] + 1,dp[i-k2] + 1....)(这里面ki为小于i的平方数)

### 代码

```cpp
class Solution {
public:
	int numSquares(int n) {
        vector<int> dp(n + 1,INT_MAX);
		for (int i = 1; i <= sqrt(n); i++) {
			dp[i*i] = 1;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j*j < i; j++) {
				dp[i] = min(dp[i - j*j] + 1, dp[i]);
			}
		}
		return dp[n];
		
    }
};
```