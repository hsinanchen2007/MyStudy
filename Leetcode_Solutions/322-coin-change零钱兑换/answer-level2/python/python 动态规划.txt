### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        max_num = float("inf")
        dp = [max_num] * (amount + 1)
        dp[0] = 0
        for i in range(amount + 1):
            for coin in coins:
                if i - coin >= 0:
                    dp[i] = min(dp[i - coin] + 1, dp[i]) 
        return dp[amount] if dp[amount] != max_num else -1
```