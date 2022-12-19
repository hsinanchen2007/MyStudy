### 解题思路
此处撰写解题思路

### 代码

```python3
from functools import reduce
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # dp[i][j] = d[i-1][j-1] if word1[i] == word[j]
        # dp[i][j] = min(d[i-1][j-1]+1, d[i][j-1]+1, d[i-1][j]+1)
        len_1 = len(word1)
        len_2 = len(word2)
        if len_1 > len_2:  # word1 < word2
            word1, word2 = word2, word1
            len_1, len_2 = len_2, len_1
        if len_1 == 0: return len_2
        dp = [i for i in range(len_1+1)]
        for i in range(1, len_2+1):
            dp[0] = i-1
            temp = dp[0]
            for j in range(1, len_1+1):
                tempNext = dp[j]
                if word1[j-1] == word2[i-1]:
                    dp[j] = temp
                else:
                    dp[j] = reduce(min, (dp[j-1], dp[j], temp)) + 1
                temp = tempNext
        return dp[-1]
```