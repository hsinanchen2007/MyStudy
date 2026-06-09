### 解题思路
dfs+剪枝

### 代码

```python3
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        coins.sort(reverse = True)
        self.res = float('inf')
        def dfs(curr, count, i):
            if curr > coins[i] * (self.res - count):
                return
            if curr == 0:
                self.res = min(self.res, count)
            elif curr < 0:
                return
            else:
                for j in range(i, len(coins)):
                    dfs(curr - coins[j], count + 1, j)
        
        dfs(amount, 0, 0)
        
        return -1 if self.res == float('inf') else self.res
```