```
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if len(p) != len(s) and '*' not in p and '.' not in p:
            return False
        #dp[i][j]代表s[:i]与p[:j]是否匹配，这样dp中的索引与s，p中的索引总是差1
        dp = [[0] * (len(p) + 1) for _ in range(len(s) + 1)]
        dp[0][0] = 1
        #初始化s=''的dp
        for i in range(len(p)):
            #如果p[:i-1]与''匹配，即dp[0][i-1]为1，且p[i]='*'，那么p[:i]也与''匹配，因为'*'可以匹配零个，即dp[0][i+1]为1
            if p[i] == '*' and dp[0][i - 1]:
                dp[0][i+1] = 1

        for i in range(len(s)):
            for j in range(len(p)):
                #如果p[:j],s[:i]匹配，且p[j] == s[i],那么p[:j+1],s[:i+1]也匹配，'.'可以匹配任意单个字符，p[j]='.'也行
                if p[j] == s[i] or p[j] == '.':
                    dp[i + 1][j + 1] = dp[i][j]
                if p[j] == '*':
                    #类似于上一个if条件
                    if p[j - 1] == '.' or p[j - 1] == s[i]:
                        dp[i + 1][j + 1] = dp[i + 1][j] or dp[i][j + 1] or dp[i + 1][j - 1]
                    else:
                        #上一个字符与当前字符不相等，可以将*匹配零个字符，相当于去掉了*以及p[j-1]
                        dp[i + 1][j + 1] = dp[i + 1][j - 1]
        return dp[len(s)][len(p)] == 1
```
