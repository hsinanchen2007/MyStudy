```
class Solution:
    def magicalString(self, n: int) -> int:
        s = "122"
        i = 2
        while(len(s) < n and i < len(s)):
            if(i%2 == 0):
                s += "1" * int(s[i])
                i += 1
            else:
                s += "2" * int(s[i])
                i += 1
        return s[:n].count('1')
```
