使用长度为N的一维数组，每次进行从前向后(i+1开始)的更新时，提前暂存左下角元素dp[i]为lb，并并暂存当前元素dp[j]为tmp，dp[j]更新后，tmp变为左下角元素，将之赋值给lb，然后交替进行。

```python []
class Solution:
    def longestPalindromeSubseq(self, s):
        n = len(s)
        dp = [0]*n
        dp[-1] = 1
        for i in range(n-2,-1,-1):
            lb = dp[i]
            for j in range(i+1,n):
                tmp = dp[j]
                if s[i] == s[j]:
                    dp[j] = lb+2
                else:
                    dp[j] = max(tmp,1) if j == i+1 else max(tmp,dp[j-1]) 
                lb = tmp
            dp[i] = 1
        return dp[n-1]
```

