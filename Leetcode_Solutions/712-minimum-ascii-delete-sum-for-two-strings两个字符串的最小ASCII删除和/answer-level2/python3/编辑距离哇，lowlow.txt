```
# -- coding: utf-8 --
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        n1 = len(s1)
        n2 = len(s2)
        if n1 == 0:
            if n2 == 0:
                return 0
            else:
                sum1 = 0
                for i in s2:
                    sum1 += ord(i)
                return sum1
        if n2 == 0:
            if n1 == 0:
                return 0
            else:
                sum1 = 0
                for i in s1:
                    sum1 += ord(i)
                return sum1

        dp = [[0] * (n2 + 1) for i in range(n1 + 1)]
        sum1 = 0
        for i in range(1, n1 + 1):
            sum1 += ord(s1[i - 1])
            dp[i][0] = sum1
        sum1 = 0
        for i in range(1, n2 + 1):
            sum1 += ord(s2[i - 1])
            dp[0][i] = sum1

        for i in range(1,n1 + 1):
            for j in range(1,n2 + 1):
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = min(dp[i - 1][j] + ord(s1[i - 1]), dp[i][j - 1] + ord(s2[j - 1]))

   
        return dp[n1][n2]
```
