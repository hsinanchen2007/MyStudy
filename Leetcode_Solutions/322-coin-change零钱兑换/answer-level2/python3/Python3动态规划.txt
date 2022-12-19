### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = {}
        def dfs(amount):
            if amount == 0:
                return 0
            if amount in dp:
                return dp[amount]
            res = float('inf')
            for i in coins:
                if i <= amount:
                    tmp = dfs(amount - i)
                    dp[amount - i] = tmp
                    if tmp != -1:
                        res = min(res, tmp + 1)
            return -1 if res == float('inf') else res
        return dfs(amount)
        
        
        # 1. 动态规划
        # dp = [-1] * (amount+1)
        # dp[0] = 0
        # for i in range(1, amount+1):
        #     tmp = float('inf')
        #     for c in coins:
        #         if c <= i and dp[i-c] != -1:
        #             tmp = min(tmp, dp[i-c] + 1)
        #     dp[i] = -1 if tmp==float('inf') else tmp
        # return dp[amount]
```