```
class Solution:
    def isNumber(self, s: str) -> bool:
        s1 = s.strip()
        n1 = len(s1)
        if n1 > 2:
            if s1[0] == "-" or s1[0] == "+":
                if s1[1] == "-" or s1[1] == "+":
                    return(False)
            try:
                float(s1)
                return(True)
            except ValueError:
                return(False)
        else:
            try:
                float(s1)
                return(True)
            except ValueError:
                return(False)
        
```
