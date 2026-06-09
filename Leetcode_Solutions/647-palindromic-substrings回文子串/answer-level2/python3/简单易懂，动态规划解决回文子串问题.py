```
class Solution:
    def countSubstrings(self, s: str) -> int:   
        dp = [0]*len(s)
        dp[0] = 1
        for i in range(1, len(s)):
            count = 1
            for j in range(i-1, -1, -1):
                if s[j:i+1]==s[j:i+1][::-1]:
                    count += 1
            dp[i] = dp[i-1] + count
        
        return dp[-1]
```
