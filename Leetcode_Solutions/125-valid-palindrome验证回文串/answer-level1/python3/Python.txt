```
class Solution:
    def isPalindrome(self, s: str) -> bool:
        l = 0
        r = len(s)-1
        while l<r:
            if s[l].isalnum() and s[r].isalnum():
                if s[l].upper()==s[r].upper():
                    l+=1
                    r-=1
                else:
                    return False
            else:
                if not s[l].isalnum():
                    l+=1
                if not s[r].isalnum():
                    r-=1
        return True
```
