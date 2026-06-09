```
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        L=len(s)
        if L<=1:return s
        for i in range(L-1,-1,-1):
            if i%2==0 and s[:i//2]==s[i//2+1:i+1][::-1]:
                break   
            elif i%2==1 and s[:(i+1)//2]==s[(i+1)//2:i+1][::-1]:
                break 
        return s[i+1:L][::-1]+s
```
