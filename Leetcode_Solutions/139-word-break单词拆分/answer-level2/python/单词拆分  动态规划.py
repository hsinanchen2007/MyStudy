### 解题思路
找到所有可能子串，dp[i]代表前i个字符可以进行拆分，若dp[i] = True ，如果还同时满足s[i+1:j]在字典中那么
dp[j] = True

### 代码

```python
class Solution:
    def wordBreak(self, s, wordDict):
        dp = [False] * (len(s)+1)
#dp[i]代表前i个字符可以进行拆分，初始化dp[0] = True 空字符在字典里
        dp[0] = True
        for i in range(len(s)):
            for j in range(i+1,len(s)+1):
                if dp[i] and s[i:j] in wordDict:
                    dp[j] = True
        return dp[-1]
```