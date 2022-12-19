### 解题思路
复杂dp, 对状态的转移要分情况讨论
一般两个字符串的dp设计的dp[i][j]都代表前i个str1和前j个str2的关系

### 代码

```python3
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # if not s or not p:
        #     return s==p
        ls, lp = len(s), len(p)
        dp = [[False]*(ls+1) for _ in range(lp+1)] # dp[i][j]代表前i个p可以匹配前j个s
        dp[0][0] = True
        for i in range(1, lp+1):
            if p[i-1]=='*':
                dp[i][0] = dp[i-1][0] or dp[i-2][0]
        for i in range(1, lp+1):
            for j in range(1, ls+1):
                if p[i-1]==s[j-1] or p[i-1]=='.':
                    dp[i][j] = dp[i-1][j-1]
                # else:
                    # if p[i-1]!='*': dp[i][j] = False
                elif p[i-1]=='*':
                    if p[i-2]!=s[j-1] and p[i-2]!='.': dp[i][j] = dp[i-2][j] # 把char*忽略掉
                    else:
                        dp[i][j] = dp[i-1][j] or dp[i-2][j] or dp[i][j-1] # 分别代表匹配一个char, 匹配0个char, 匹配多个char
        return dp[-1][-1]
```