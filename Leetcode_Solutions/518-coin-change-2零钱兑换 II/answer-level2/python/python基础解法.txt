### 解题思路
动态规划来做，这是一个完全背包问题。首先状态表示dp[i][j],状态计算 dp[i][j] = dp[i-1][j] + dp[i][j-t*coins[i]]
可以简化为dp[i][j] = dp[i-1][j] + dp[i][j-c]
从二维简化为一维：
dp[j] = dp[j] + dp[j-c]

### 代码

```python3
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [0] * (amount+1)
        dp[0] = 1
        for i in coins:
            for j in range(i, amount+1):
                dp[j] += dp[j-i]
        return dp[amount]
```