### 解题思路
dp[i][j]记录的是s[i:j + 1]是否为回文串，分成以下三种情况讨论：
（1）i == j。
（2）j == i + 1。
（3）other。

### 代码

```python
class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        if length == 0:
            return []
        dp = [[0] * length for _ in range(length)]
        cnt = 0
        for i in range(0, length):
            for j in range(i, length):
                # print(j - i, j)
                if i == 0:
                    dp[j][j] = 1
                    cnt += 1
                elif i == 1 and s[j - 1] == s[j]:
                    dp[j - 1][j] = 1
                    cnt += 1
                elif s[j - i] == s[j] and dp[j - i + 1][j - 1]:
                    dp[j - i][j] = 1
                    cnt += 1
                    
        return cnt
```