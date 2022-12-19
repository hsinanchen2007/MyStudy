### 解题思路
和前面的正则匹配思路类似。

### 代码

```python3
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n1=len(s)
        n2=len(p)
        dp=[[False for i in range(n2+1)] for j in range(n1+1)]#dp[i][j]对应s[:i]和p[:j]是否匹配
        dp[0][0]=True
        for i in range(1,n2+1):
            if dp[0][i-1]==True and p[i-1]=="*":
                dp[0][i]=True
        for i in range(1,n1+1):
            for j in range(1,n2+1):
                if dp[i-1][j-1]:
                    dp[i][j]=(s[i-1]==p[j-1] or p[j-1]=="?" or p[j-1]=="*")
                else:
                    dp[i][j]=(p[j-1]=="*" and (dp[i-1][j] or dp[i][j-1]))                
        return dp[n1][n2]

```