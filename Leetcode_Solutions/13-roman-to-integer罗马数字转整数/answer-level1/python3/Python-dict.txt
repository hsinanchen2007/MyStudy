```
class Solution:
    def romanToInt(self, s: str) -> int:
        dict = {'I':1, 'IV':3, 'V':5, 'IX':8, 'X':10, 'XL':30, 'L':50, 'XC':80, 'C':100, 'CD':300, 'D':500, 'CM':800, 'M':1000}
        ans = 0
        for i in range(len(s)):
            if i<len(s)-1 and dict[s[i]]<dict[s[i+1]]:
                ans-=dict[s[i]]
            else:
                ans+=dict[s[i]]
        return ans
```
