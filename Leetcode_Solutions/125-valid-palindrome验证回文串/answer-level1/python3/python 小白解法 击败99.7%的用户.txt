```
class Solution:
    def isPalindrome(self, s: str) -> bool:
        for i in [" ",",",":",".","@","#","-","?","\'","/","\\","|","\"",";","!","(",")","`"]:
            s = s.replace(i,"")
        s = s.lower()
        print(s)
        if s == s[::-1]:
            return True
        else:
            return False
```
