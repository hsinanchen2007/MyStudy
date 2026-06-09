```
class Solution:
    def numDecodings(self, s: str) -> int:
        if len(s) == 1:
            return 1 if s[0] != "0" else 0
        if s[0] == "0":
            return 0
        a = 1
        if s[1] == "0" and s[0] not in "12":
            b =  0
        elif s[0] in "1" and s[1] not in  "0":
            b = 2
        elif s[0] in "2" and s[1] not in "0789":
            b = 2
        else:
            b =  1
        last = s[1]
        for i in s[2:]:
            if i == "0" and last not in "12":
                return 0
            if last in "2" and i not in  "0789" or last == "1" and i != "0":
                a, b = b, a+b
            elif i != "0":
                a, b = b, b
            else:
                a, b = a, a 
            last = i
        return b
            
```
