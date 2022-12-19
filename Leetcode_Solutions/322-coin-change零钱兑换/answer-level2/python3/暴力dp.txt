### 解题思路
1. 定义问题，dp[n]为amount为n时所需的最少硬币个数
2. 初始化，dp[1...n] = -1, dp[0] = 0
3. 转移方程，对于在coins列表中的coin，只有当dp[n-coin]存在时，dp[n]才有可能实现，所以，对所有在coins中的coin遍历，dp[n-coin] = min(dp[n], dp[n-coin]+1) if dp[n] != -1 else dp[n-coin] + 1

### 代码

```python3
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [-1 for i in range (amount + 1)]
        dp [0] = 0
        for i in range (amount + 1):
            if i in coins:
                dp[i] = 1
            else:
                for coin in coins:
                    if i - coin > 0 and dp[i-coin] != -1:
                        dp[i] = min(dp[i-coin]+1, dp[i]) if dp[i] != -1 else dp[i-coin]+1
        return dp[amount]        
```