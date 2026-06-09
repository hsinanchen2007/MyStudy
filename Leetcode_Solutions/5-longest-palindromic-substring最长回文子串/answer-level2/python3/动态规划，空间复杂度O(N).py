### 解题思路
动态规划。时间复杂度O(n2),空间复杂度O(n)

数组p[j]=i代表第j个字符到第i个字符为回文字符串

所以要判断第j个字符到第i个字符的字串是否回文字符串，只需判断  p[j+1] == i-1 and s[i] == s[j] 

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) == 0:
            return ""        
        p = [[False] * len(s) for i in range(0,len(s))]
        max_start = 0
        max_len = 1
        for i in range(1,len(s)):
            for j in range(0, i):
                if i-1 <= j+1:
                    p[j] = i if s[i] == s[j] else p[j]
                else:
                    p[j] = i if p[j+1] == i-1 and s[i] == s[j] else p[j]
                if p[j] == i and i-j+1 > max_len:
                    max_start = j
                    max_len = i-j+1
        return s[max_start:max_start+max_len]
                    
```