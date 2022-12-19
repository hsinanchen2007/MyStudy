```
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        s = [x for x in s]
        s.insert(0, '')
        p = [x for x in p]
        p.insert(0, '')
        m = len(s)
        n = len(p)
        dp = [[False for _ in range(n)] for _ in range(m)]
        dp[0][0] = True
        for i in range(1, n):
            if p[i] == '*':
                dp[0][i] = dp[0][i-1]
        for i in range(1, m):
            for j in range(1, n):
                if s[i] == p[j] or p[j] == '?':
                    dp[i][j] = dp[i-1][j-1]
                elif p[j] == '*':  # 仔细考虑
                    dp[i][j] = (dp[i][j-1] or dp[i-1][j-1] or dp[i-1][j])
        return dp[-1][-1]


```

![QQ图片20191018203630.png](https://pic.leetcode-cn.com/e1ee2410910481acc9ca2598ec602e326cd0dbb041b16266f31ad2bdfeccefca-QQ%E5%9B%BE%E7%89%8720191018203630.png)

