### 解题思路
动态规划，比较简单吧，注意一下循环顺序就行

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        length = len(s)
        if length == 1:
            return s
        start = end = 0
        resultLen = 0
        dp = [[True for i in range(length)] for i in range(length)]
        for j in range(1, length):
            for i in range(0, j):
                dp[i][j] = ((s[i] == s[j]) and dp[i+1][j-1])
                nowLen = j - i
                if dp[i][j] and nowLen > resultLen:  # 判断是否更长
                    start, end = i, j
                    resultLen = nowLen
        return s[start:end+1]


```