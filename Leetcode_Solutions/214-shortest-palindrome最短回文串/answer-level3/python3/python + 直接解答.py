```python
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        index = 0
        pre, rev = '', ''
        for i in range(len(s)):
            pre += s[i]
            rev = s[i] + rev
            if pre == rev: index = i
        
        res = s[index + 1:][::-1] + s[:index + 1] + s[index + 1:]
        return res
```