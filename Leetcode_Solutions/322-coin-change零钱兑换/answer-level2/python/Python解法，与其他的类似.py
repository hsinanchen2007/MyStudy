动态规划的核心思想在找问题与子问题的DP方程：
F(n) = min(F(n - 1) +1, F(n - 2) + 1, F(n - 5) + 1)
当前coins = (1, 2, 5)

```python
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        res = [0 for _ in range(amount + 1)]
        
        for i in range(1, amount + 1):
            cost = float('inf')
            for c in coins:
                if i - c >= 0:
                    cost = min(cost, res[i - c] + 1)
            res[i] = cost

        print(res)
        if res[amount] == float('inf'):
            return -1
        else:
            return res[amount]
```

动态规划问题一般采用反解的思维来解决实际问题。

