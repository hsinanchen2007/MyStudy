```
class Solution:
    def romanToInt(self, s: str) -> int:
        sum0 = 0
        dic = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        for i in range(len(s)):
            if i < len(s)-1 and dic[s[i]] < dic[s[i+1]] :
                sum0 -= dic[s[i]]
            else:
                sum0 += dic[s[i]]
        return sum0
```
