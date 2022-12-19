### 解题思路
只需要求出最公共长子序列（1143题），然后算出总字符串长度，减去二倍的子序列长度即可。

### 代码

```python
class Solution(object):
    def minDistance(self, word1, word2):
        r = len(word1)
        c = len(word2)
        if r == 0 or c == 0:
            return r or c
        dp = [[0]*(c+1)for i in range(r+1)]
        for i in range(1,r+1):
            for j in range(1,c+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1])
        return  r+c-dp[-1][-1]*2
```