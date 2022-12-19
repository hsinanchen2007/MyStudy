### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:return 0
        dp = [0]*len(s)
        dp[0] = 1
        dic = {s[0]:0}
        for i in range(1,len(s)):
            if s[i] not in dic:dic[s[i]] = i;dp[i] = dp[i-1]+1
            else:
                d = i-dic[s[i]]
                if d<=dp[i-1]:dp[i] = d
                else:dp[i] = dp[i-1]+1
                dic[s[i]] = i
        return max(dp)
```