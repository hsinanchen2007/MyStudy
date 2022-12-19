### 解题思路
通式就是$DP[i] = LCP(DP[i-1], strs[i]])$
一日代码没烦恼，今天就把老八DP前缀搞！
臭豆腐，俘虏，来循环！
你问这前缀拙地行不行？
奥利给，写它都完了！


### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0: return ""
        if len(strs) == 1: return strs[0]
        dp = [""]*len(strs)
        def cpref2(s1, s2):
            for i in range( min(len(s1), len(s2)) ):
                if s1[i] != s2[i]:
                    return s1[:i]
            return s1[:min(len(s1), len(s2))]
        dp[0] = strs[0]
        for i in range(1, len(strs)):
            dp[i] = cpref2(dp[i-1], strs[i])
        return dp[-1]
        
```