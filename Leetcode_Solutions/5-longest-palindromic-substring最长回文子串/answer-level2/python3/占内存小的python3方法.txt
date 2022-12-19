```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        max_s = 0
        ls = ''
        for i in range(len(s)):
            j = 1
            while i>=j and i+j<=len(s)-1 and s[i-j]==s[i+j]:
                j += 1
            if 2*j-1>max_s:
                max_s = 2*j-1
                ls = s[i-j+1:i+j]
        for i in range(len(s)):
            j = 1
            while i>=j-1 and i+j<=len(s)-1 and s[i-j+1]==s[i+j]:
                j += 1
            if 2*j-2>max_s:
                max_s = 2*j-2
                ls = s[i-j+2:i+j]
        return ls
```
