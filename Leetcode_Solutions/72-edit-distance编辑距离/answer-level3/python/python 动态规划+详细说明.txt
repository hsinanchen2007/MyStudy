### 解题思路
dp[i][j] 代表 word1的前i个字符转化为word2前j个字符的最优解
若word1[i] == word2[j], dp[i][j] = dp[i-1][j-1] (从i-1,j-1状态不用经过任何改变可以变为i, j)
若不相等时, dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1
dp[i-1][j-1] 可以通过替换word1[i]转变为dp[i][j]
dp[i][j-1] 可以通过删除word1[i]转变为dp[i][j]
dp[i-1][j] 可以通过插入word1[i]转变为dp[i][j]

从上述可以看出能压缩dp空间

### 代码

```python
class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        l1, l2 = len(word1), len(word2)
        dp = [[0] * (l2 + 1)]
        dp.append([i for i in xrange(l2+1)])

        flag = 0
        for i in xrange(1, l1 + 1):
            dp[flag][0] = i
            for j in xrange(1, l2 + 1):
                if word1[i-1] == word2[j-1]:
                    dp[flag][j] = dp[1-flag][j-1]
                else:
                    dp[flag][j] = 1 + min(
                        dp[flag][j-1],
                        dp[1-flag][j-1],
                        dp[1-flag][j],
                    )
            flag = 1 - flag

        return dp[1-flag][-1]
```