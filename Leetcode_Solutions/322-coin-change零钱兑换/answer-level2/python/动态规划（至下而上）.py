
### 代码

```python3
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        res = [float('inf')] * (amount+1)
        res[0] = 0
        for  i in range(1, amount+1):
            for coin in coins:
                if i >= coin:
                    res[i] = min(res[i], res[i-coin]+1)
        return res[-1] if res[-1] != float('inf') else -1
```