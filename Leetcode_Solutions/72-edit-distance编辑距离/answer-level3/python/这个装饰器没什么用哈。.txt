### 解题思路
此处撰写解题思路

### 代码

```python3
from functools import *
class Solution:
    @lru_cache
    def minDistance(self, word1: str, word2: str) -> int:
        # dp[i][j] = d[i-1][j-1] if word1[i] == word[j]
        # dp[i][j] = min(d[i-1][j-1]+1, d[i][j-1]+1, d[i-1][j]+1)
        i = len(word1)
        j = len(word2)
        if i == 0: return j
        if j == 0: return i
        if word1[i-1] == word2[j-1]:
            return self.minDistance(word1[:i-1], word2[:j-1])
        else:
            return 1 + reduce(min, [self.minDistance(word1, word2[:j-1]),
                                    self.minDistance(word1[:i-1], word2),
                                    self.minDistance(word1[:i-1], word2[:j-1])])
```