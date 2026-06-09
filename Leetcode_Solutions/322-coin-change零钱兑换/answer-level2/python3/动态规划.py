### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [amount+10 for _ in range(amount+1)]
        dp[0]=0
        for i in range(1,amount+1):
            for j in range(len(coins)):
                if i>=coins[j]:dp[i] = min(dp[i],dp[i-coins[j]]+1)
        if dp[amount] != amount+10:return dp[amount]
        return -1
```