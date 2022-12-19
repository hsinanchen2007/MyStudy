### 解题思路
此处撰写解题思路

### 代码

```python
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        l = len(s)
        dp  = [1] + [0] * l
        for i in range(l + 1):
            for word in wordDict:
                if i >= len(word) and s[i - len(word): i] == word:
                    if dp[i - len(word)] == 1:
                        dp[i] = 1
                        break
        return  dp[-1]


```