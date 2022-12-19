### 解题思路
执行用时 :840 ms, 在所有 Python 提交中击败了84.86%的用户
内存消耗 :12.2 MB, 在所有 Python 提交中击败了22.61%的用户


### 代码

```python
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0
        
        for coin in coins:
            for x in range(coin, amount + 1):
                dp[x] = min(dp[x], dp[x - coin] + 1)
        return dp[amount] if dp[amount] != float('inf') else -1  
```