贡献哈希表+滑动窗口python代码：

```python []
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        n = len(s)
        dp = [1] * n
        hashl = [-1] * 256
        hashl[ord(s[0])] = 0
        for i in range(1,n):
            if s[i] != s[i-1] and hashl[ord(s[i])] < i - dp[i-1]:
                dp[i] = dp[i-1] + 1
            elif s[i] != s[i-1] and hashl[ord(s[i])]  >= i - dp[i-1]:
                dp[i] = i - hashl[ord(s[i])]
            
            hashl[ord(s[i])] = i
        #print(dp)
        return max(dp)
```
