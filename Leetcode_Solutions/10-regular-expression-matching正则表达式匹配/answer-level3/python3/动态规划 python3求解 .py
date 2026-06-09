### 解题思路
首先要明确一点：pattern字符串中，如果有 星号，星号前面的字母和星号是一体的。
为了分析方便，我们首先将p拆分成list列表，如p为"ab*c*cc.*..", 拆分后为[a, b*, c*, c, c, .*, ., .]

之后开始匹配，我们使用动态规划的思想。

dp变量很简单，dp[i][j]表示s中最开始长度为i的部分同p中长度为j的部分匹配。同一般的dp数组不同，此处dp的shape是(len(s)+1, len(p)+1), 多出来这一行一列表示s或者p为空时的匹配情况。因为当s为空时，如果p中全部是带星号的pattern，返回结果也是True，我们必须在dp中引入这种情况。

之后考虑动规递推公式。

####1. 初始情况
对于dp[0][j]：也即s为空串的情况，当且仅当dp[0][j-1]为空，且p[j]为带星号的pattern时为True
对于dp[i][0]: 也即p为空模式的情况，当且仅当s也为空串时为True

####2. 引申情况
当i>0, j>0时，对于dp[i][j]有三种可能的情况（注意这里的i,j是匹配字符串的长度，因此最后一个对应字符应该是i-1, j-1, 这里如果搞错会很头疼）：
1. dp[i-1][j-1]为True，考虑s[i-1]和p[j-1]的匹配，如果能匹配上dp[i][j]为True；
2. dp[i-1][j]为True，考虑s[i-1]和p[j-1]的匹配，此处匹配方式同题目说明的有区别。因为dp[i-1][j]为True，所以相当于p[j-1]之前已经匹配过一次s[i-1]之前的字符，所以要求p[j-1]是能多次匹配的模式（带星号）,如果p[j-1]带星号且能同s[i-1]匹配，那么dp[i][j]为True；
3. dp[i][j-1]为True，考虑p[j-1], 因为s字符串已经被p[j-1]之前的模式匹配过，如果p[j-1]允许空匹配（带星号）则dp[i][j]为True。
 
以上三种情况只要有一种成立，dp[i][j]即为True，三种情况对应三种匹配方式。

### 代码

```python3
import numpy as np

class Solution:
    
    def seperatePattern(self, p: str):
        index, new_p = 0, []
        while index < len(p) - 1:
            if p[index + 1] == '*':
                new_p.append(p[index:index + 2])
                index += 2
            else:
                new_p.append(p[index])
                index += 1
        if index == len(p) - 1:
            new_p.append(p[index])
        return new_p

    def match_this(self, i, j):
        # dp[i-1][j-1] match_this(i, j)
        return True if j[0] == '.' else i == j[0]

    def match_p_pre(self, i, j):
        # dp[i-1][j] match_p_pre(i, j)
        return False if len(j) == 1 else i == j[0] or j[0] == '.'

    def match_s_pre(self, i, j):
        # dp[i][j-1] match_s_pre(i, j)
        return True if len(j) == 2 else False

    def isMatch(self, s: str, p: str) -> bool:
        p = self.seperatePattern(p)
        dp = np.zeros((len(s)+1, len(p)+1), dtype=np.bool)
        dp[0][0] = True
        for i in range(1, len(s)+1):
            dp[i][0] = False
        for j in range(1, len(p)+1):
            dp[0][j] = dp[0][j-1] and len(p[j-1]) > 1

        for i in range(1, len(s)+1):
            for j in range(1, len(p)+1):
                up = dp[i - 1][j] and self.match_p_pre(s[i-1], p[j-1])
                left = dp[i][j - 1] and self.match_s_pre(s[i-1], p[j-1])
                up_left = dp[i - 1][j - 1] and self.match_this(s[i-1], p[j-1])
                dp[i][j] = up or left or up_left

        return bool(dp[len(s)][len(p)])
```