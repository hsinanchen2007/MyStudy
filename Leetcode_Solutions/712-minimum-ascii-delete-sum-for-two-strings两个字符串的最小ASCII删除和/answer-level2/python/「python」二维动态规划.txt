假设`s1`的长度为`m`，`s2`的长度为`n`。

1. 构建二维`dp`数组，`dp`数组的大小为`(m+1)*(n+1)`。
    初始化`dp`数组：`dp[i][0]`表示`s1`前`i`个字符对应的ASCII之和`(0<=i<=m)`，`dp[0][j]`表示`s2`前`j`个字符对应的ASCII之和`(0<=j<=n)`。
    边界的第1行和第1列意味着，当`s1/s2`其中一个为空，另一个不为空时，需要删除的字符的ASCII之和即为不为空字符串所有字符的ASCII之和。

2. 用`dp[i][j]`表示，为使字符串`s1[:i]`和`s2[:j]`达到相同，需要删除的字符串的ASCII值的最小和。
    因此，分为两种情况：
    - 当`s1[i] = s2[j]`时，两个子字符串`s1[:i]`和`s2[:j]`的结尾元素相同，则`dp[i][j] = dp[i-1][j-1]`；
    「理解」：`dp[i-1][j-1]`代表使两个子字符串`s1[:i-1]`和`s2[:j-1]`达到相同，需要删除的ASCII之和。换句话说，删除和为`dp[i-1][j-1]`的元素之后，`s1[:i-1]`和`s2[:j-1]`已经相同，此时若`s1[i] = s2[j]`，则说明`s1[:i]`和`s2[:j]`也已经相同，无需额外删除其他元素。

    - 当`s1[i] != s2[j]`时，则需要删除`s1`或`s2`的末尾元素，删除依据则为元素的ASCII值，此时`dp[i][j] = min(dp[i-1][j] + ord(s1[i-1], dp[i][j-1] + ord(s2[j-1]))`。
    「理解」：`dp[i-1][j]`代表`s1[:i-1]和s2[:j]`达到相同，需要删除的ASCII之和。此时，对于`dp[i][j]`位置，`s1[i]`是一个多余的元素，如果加入`s1`，则子字符串`s1[:i]`和`s2[:j]`不相同，因此需要删除`s1[i]`，删除`s1[i]`后，需要产生的ASCII代价为`dp[i-1][j] + ord(s1[i-1])`。同理，`dp[i][j-1]`代表`s1[:i]`和`s2[:j-1]`达到相同，需要删除的ASCII之和，此时，删除`s2[j]`需要产生的ASCII代价为`dp[i][j-1] + ord(s2[j-1])`。

        两个代价取最小`min`即为`dp[i][j]`的代价。

3. 返回dp[-1][-1]。
```
class Solution(object):
    def minimumDeleteSum(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        m = len(s1)
        n = len(s2)

        # 建立二维dp数组并初始化
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m):
            dp[i + 1][0] = dp[i][0] + ord(s1[i])
        for j in range(n):
            dp[0][j + 1] = dp[0][j] + ord(s2[j])
        # print("init_dp: " + str(dp))  

        for i in range(1, m+1):
            for j in range(1, n+1):
                if s1[i-1] == s2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j] + ord(s1[i-1]), dp[i][j-1] + ord(s2[j-1]))

        # print("final_dp: " + str(dp))    
         
        return dp[-1][-1]

```
