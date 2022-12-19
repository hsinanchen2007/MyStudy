### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        memo = {0:0}
        def fun(amount):
            if amount in memo:
                return memo[amount]
            res = float('inf')
            for coin in coins:
                if amount >= coin:
                    res = min(res, fun(amount - coin) + 1)
            memo[amount] = res
            return res
        return fun(amount) if fun(amount) != float('inf') else -1
```