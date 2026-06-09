### 解题思路
此处撰写解题思路

### 代码

```python3
from functools import reduce
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # when word[i] == word[j]
        # d[i][j] = d[i-1][j-1]     替换           A插入            B插入  #算法的正确性有点难以理解。
        # otherwise  d[i][j] = min(d[i-1][j-1]+1, d[i-1][j]+1, d[i][j-1]+1)
        # 很多重复计算不想改了。
        dp = [[None]*(len(word2)+ 1) for i in range((len(word1)+1))]
        for i in range(len(word1)+1):
            dp[i][0] = i  
        for j in range(len(word2)+1):
            dp[0][j] = j
        for i in range(1, len(word1)+1):
            for j in range(1, len(word2)+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = 1 + reduce(min, [dp[i-1][j-1], dp[i-1][j], dp[i][j-1]])
        return dp[-1][-1]
```