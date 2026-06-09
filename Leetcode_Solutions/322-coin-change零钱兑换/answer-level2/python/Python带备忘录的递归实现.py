### 代码

```python
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        # 备忘录
        memo = dict()
        # 定义：要凑出n，至少需要dp(n)个硬币
        def dp(n):
            # 做选择，选择需要硬币最少的那个结果
            if n in memo:
                return memo[n]
            if n == 0:
                return 0
            if n < 0:
                return -1
            
            # 求最小值，所以初始化为正无穷
            res = float('INF')

            for coin in coins:
                subproblem = dp(n - coin)
                if subproblem == -1: continue
                res = min(res, 1 + subproblem)
            
            memo[n] = res if res != float('INF') else -1
            return memo[n]
        
        # 我们要求的问题是dp(amount)
        return dp(amount)
```