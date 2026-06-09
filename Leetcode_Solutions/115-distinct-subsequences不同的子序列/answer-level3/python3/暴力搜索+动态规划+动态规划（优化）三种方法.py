暴力搜索超时了，暴力搜索是动态规划的基础；两个动态规划都过了

```
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        #return self.helper(s, 0, t, 0)
        return self.helper3(s,t)

    def helper(self, s, i, t, target):
        if target == len(t) and i == len(s) :
            return 1
        if target == len(t):
            return 1
        if i == len(s):
            return 0
        res = 0
        if s[i] == t[target]:
            res = self.helper(s, i + 1, t, target + 1) + self.helper(s, i + 1, t, target)
        else:
            res = self.helper(s, i + 1, t, target)
        return res

    def helper2(self,s,t):
        dp = [[0 for i in range(len(t)+1)]for j in range(len(s)+1)]
        for i in range(0,len(s)+1):
            dp[i][-1] = 1
        for i in range(len(s)-1,-1,-1):
            for j in range(0,min(i+2,len(t))):
                if s[i] == t[j]:
                    dp[i][j] = dp[i+1][j+1]+dp[i+1][j]
                else:
                    dp[i][j] = dp[i+1][j]
        return dp[0][0]
    
    def helper3(self,s,t):
        dp = [0 for _ in range(len(t)+1)]
        dp[-1] = 1
        for i in range(len(s)-1,-1,-1):
            for j in range(0,min(i+2,len(t))):
                if s[i] == t[j]:
                    dp[j] = dp[j+1]+dp[j]
                else:
                    dp[j] = dp[j]
        return dp[0]
```
