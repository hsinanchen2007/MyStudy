### 解题思路
记忆化加速递归

### 代码

```python3
class Solution:
    def integerReplacement(self, n: int) -> int:
        return self.dfs(n, {})
    
    def dfs(self, n, memo):
        if n in memo:
            return memo[n]
        if n == 1:
            return 0
        res = 0
        if n & 1 == 1:
            res = 1 + min(self.dfs(n+1, memo), self.dfs(n-1, memo))
        else:
            res = 1 + self.dfs(n//2, memo)
        memo[n] = res
        return res
```