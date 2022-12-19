![Screen Shot 2020-02-13 at 11.53.01 AM.png](https://pic.leetcode-cn.com/8fe95487a5533e247577d1a14479aa17940f282b2dacf606a466a8ba05b21ae4-Screen%20Shot%202020-02-13%20at%2011.53.01%20AM.png)


定义一个二维数组dp，dp[i][j]表示s的前i个字符和p的前j个字符是匹配的
dp[i][j]的计算方式如下
- 首先设置dp[0][0]为true，因为两个空字符是匹配的
- 如果i = 0, 那么表示以空字符串去匹配p的前j个字符，我们期望p[j] == *, 这样*之前的字符不用出现，dp[i][j] = p[j] == * and dp[i][j-2]
- 如果s[i] == p[j]那么，直接看i-1, 和j-1是不是匹配的，dp[i][j] = dp[i-1][j-1]
- 最后就是需要处理*的情况，有两种选择，重复*前字符一次，或者不要这个字符，只要其中一个能匹配就行
    - 不要前一个字符， dp[i][j-2]
    - 重复一次，需要满足条件p[j-1] == s[i] 或者p[j-1] == \'.\', dp[i-1][j]

最后返回dp[m][n]就是能不能匹配的结果

```python3
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        s, p = '#'+s, '#'+p
        m, n = len(s), len(p)
        dp = [[False]*n for _ in range(m)]
        dp[0][0] = True
        
        for i in range(m):
            for j in range(1, n):
                if i == 0:
                    dp[i][j] = j > 1 and p[j] == '*' and dp[i][j-2]
                elif p[j] in [s[i], '.']:
                    dp[i][j] = dp[i-1][j-1]
                elif p[j] == '*':
                    dp[i][j] = j > 1 and dp[i][j-2] or p[j-1] in [s[i], '.'] and dp[i-1][j]
                else:
                    dp[i][j] = False
        return dp[-1][-1]





```