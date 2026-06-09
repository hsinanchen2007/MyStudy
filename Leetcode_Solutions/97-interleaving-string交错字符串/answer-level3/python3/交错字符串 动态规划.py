### 解题思路
python3 动态规划

首先，如果s3的长度不等于s1与s2长度之和则一定不对，返回0

初始化dp数组，第一维的第i位为s1的前i个字符组成的串，第二维的第j位表示s2的前j个字符组成的串，dp数组记录s1的前i位和s2的前j位是否交错组成了s3的前i+j位。

我们知道，空串与空串交错得空串，所以dp[0][0]取值为1。

而任意字符串与空串交错结果为该字符串本身，所以可以对dp[i][0]和dp[0][j]赋值。

最后，对于s3的前i + j位,如果s1的前i位与s2的前j - 1位可以交错得到s3的前i + j - 1位，那么只要s3的第i + j位的值与s2的第j位相同，即可认为可交错而成。反之亦然。

因此可以得到状态转移公式为：

dp[i][j] = (dp[i - 1][j] and c == s1[i - 1]) or (dp[i][j - 1] and c == s2[j - 1])


### 代码

```python3
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s3) != len(s1) + len(s2):
            return 0
        dp = [[0 for i in range(len(s2) + 1)] for j in range(len(s1) + 1)]
        dp[0][0] = 1
        for i in range(1, len(s1) + 1):
            dp[i][0] = 1 if s1[:i] == s3[:i] else 0
        for i in range(1, len(s2) + 1):
            dp[0][i] = 1 if s2[:i] == s3[:i] else 0
        for i in range(1, len(s1) + 1):
            for j in range(1, len(s2) + 1):
                c = s3[i + j - 1]
                dp[i][j] = (dp[i - 1][j] and c == s1[i - 1]) or (dp[i][j - 1] and c == s2[j - 1])
        return dp[len(s1)][len(s2)]
```