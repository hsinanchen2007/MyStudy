```
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:

        s_len = len(s)
        t_len = len(t)
        if s_len<=0:
            return True
        elif s_len>t_len:
            return False
        #dp[i][j]表示长度为i的字符串s是否为长度为j的字符串t的子序列
        dp = [[False for i in range(t_len+1)] for i in range(s_len+1)]
        for i in range (t_len+1):
            dp[0][i] = True

        for i in range(1,s_len+1):
            for j in range(1,t_len+1):
                if s[i-1]==t[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = dp[i][j-1]

        return dp[s_len][t_len]
```
