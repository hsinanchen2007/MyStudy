### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def longestCommonSubsequence(self, text1, text2):
        """
        :type text1: str
        :type text2: str
        :rtype: int
        """

        """
        # O(m*n)空间
        len1, len2 = len(text1), len(text2)
        res = 0
        dp = [[0]*(len2+1) for _ in range(len1+1)]
        for i in range(1, len1+1, 1):
            for j in range(1, len2+1, 1):
                if text1[i-1]==text2[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
                res = max(res, dp[i][j])
        return res
        """

        # O(m)空间
        len1, len2 = len(text1), len(text2)
        res = 0;
        last, temp = 0, 0;
        dp = [0]*(len2+1)
        for i in range(len1):
            last = 0
            for j in range(len2):
                temp = dp[j+1]
                if text1[i]==text2[j]:
                    dp[j+1] = last + 1
                else:
                    dp[j+1] = max(dp[j+1], dp[j])
                last = temp
                res = max(res, dp[j+1])
        return res
```