一、空间复杂度O(mn)
```python []
class Solution:
    def minDistance(self, s1,s2):
        m, n = len(s1), len(s2)
        dp = [[0]*(n+1) for _ in range(m+1)]
        for i in range(1,m+1):
            dp[i][0] = i
        for j in range(1,n+1):
            dp[0][j] = j
        for i in range(1,m+1):
            for j in range(1,n+1):
                if s1[i-1] == s2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1)
        
        return dp[m][n]
```
二、空间复杂度O(n)
![Screenshot from 2019-09-04 05-43-16.png](https://pic.leetcode-cn.com/8f6828b13efd58f422919b266e8f2871a748ec9815f3c77a1dbdcd8153c5b4a4-Screenshot%20from%202019-09-04%2005-43-16.png)
```python []
class Solution(object):
    def minDistance(self, s1, s2):
        m, n = len(s1), len(s2)
        dp = [0] * (n + 1) 
        for j in range(1, n + 1):
            dp[j] = j
        for i in range(1, m + 1):
            lt = dp[0]
            dp[0] = i
            for j in range(1, n + 1):
                up = dp[j]
                if s1[i - 1] == s2[j - 1]:
                    dp[j] = lt
                else:
                    dp[j] = min(up, dp[j - 1], lt) + 1
                lt = up
        return dp[n]
```

