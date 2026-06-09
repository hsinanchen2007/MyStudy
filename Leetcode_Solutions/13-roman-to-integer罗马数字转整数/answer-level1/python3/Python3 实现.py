```
class Solution:
    def romanToInt(self, s: str) -> int:
        a = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        b = 0
        for i in s:
            b += a[i]
        if ('IV' in s) == True or ('IX' in s) == True:
            for i in range(s.count('IV') + s.count('IX')):
                 b -= 2
        if ('XL' in s) == True or ('XC' in s) == True:
            for i in range(s.count('XL') + s.count('XC')):
                 b -=20
        if ('CD' in s) == True or ('CM' in s) == True:
            for i in range(s.count('CD') + s.count('CM')):
                 b -= 200
        else:
            pass
        return b
```
