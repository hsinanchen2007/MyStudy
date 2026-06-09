536 ms	13.5 MB
```
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        i=len(s)
        while s[:i][::-1]!=s[:i]:
            i-=1
        return s[i:][::-1]+s
```
