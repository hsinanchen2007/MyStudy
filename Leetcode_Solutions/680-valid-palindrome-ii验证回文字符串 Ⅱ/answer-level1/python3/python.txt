```
class Solution:
    def validPalindrome(self, s: str) -> bool:
        
        is_it = lambda s: s == s[::-1]
        
        l, r = 0, len(s)-1
        
        while l < r:
            if s[l] == s[r]:
                l += 1
                r -= 1
            else:
                return is_it(s[l+1:r+1]) or is_it(s[l:r])
        
        return True
```