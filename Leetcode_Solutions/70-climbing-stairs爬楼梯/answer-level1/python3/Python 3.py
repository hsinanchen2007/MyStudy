### 解题思路
思路一
DP動態規劃
### 代码
```
class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 1:
            return 1
        dp[0]*(n+1)
        dp[1] = 1
        dp[2] = 2
        for i in range(3, n+1):
            dp[i] = dp[i-1]+dp[i-2]
        return dp[n]
```

### 解题思路
思路二
用Functools的lru_cache處理重複計算的部分
### 代码

```python3
class Solution:
    import functools

    @functools.lru_cache(maxsize=None)
    def climbStairs(self, n: int) -> int:
        if n <= 1: return 1
        return self.climbStairs(n-1) + self.climbStairs(n-2)

```