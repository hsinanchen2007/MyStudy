```
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.upper()
        s = "".join([i for i in s if (65 <= ord(i) <= 90) or (48 <= ord(i) <= 57)])
        return s == s[::-1]
```
