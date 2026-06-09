```
class Solution:
    def grayCode(self, n: int) -> List[int]:
        dp = [0]
        for i in range(1, n+1):
            dp += [n + 2**(i-1) for n in dp[::-1]]
        return dp 
```
解释：
dp[n] = dp[n-1] + 
        dp[n-1] 反转加 2**(n-1)