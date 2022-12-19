对于当前索引 i 的状态，如果它之前的某个状态 j 可以被划分，那么只要判断 j 到 i 的这个单词是否在 wordDict 里，就可以确定状态 i 也是可以被划分的。

```Python
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = [False] * (len(s) + 1)
        dp[0] = True
        for i in range(1, len(s) + 1):
            for j in range(i):
                if dp[j] and (s[j: i] in wordDict):                    
                    dp[i] = True
                    break
        return dp[len(s)]
```
