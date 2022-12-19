```python
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        
        # solution: DP
        if t == '' : return 1
        if s == '' or len(t) > len(s): return 0
        dp = [0] * len(s)
        for i in range(len(t)):
            left = 0
            for j in range(len(s)):
                if i == 0:
                    if s[j] == t[i]: dp[j] = 1
                    continue
                pre = dp[j]
                dp[j] = left if s[j] == t[i] else 0
                left += pre
        return sum(dp)
```