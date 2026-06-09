### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0
        for i in range(len(coins)):
            for j in range(coins[i],amount+1):
                dp[j] = min(dp[j],dp[j-coins[i]]+1)
        return -1 if dp[-1]==float('inf') else dp[-1]

```