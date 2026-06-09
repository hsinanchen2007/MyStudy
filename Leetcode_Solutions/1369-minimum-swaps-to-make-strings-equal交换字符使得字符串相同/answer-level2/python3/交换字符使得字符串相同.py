```
class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        if len(s1) != len(s2):
            return -1
        
        length = len(s1)
        xnum = 0
        ynum = 0
        Neg = 0
        Pos = 0
        for i in range(length):
            if s1[i] == 'x' and s2[i] == 'y':
                xnum += 1
                ynum += 1
                Neg += 1
            if s1[i] == 'y' and s2[i] == 'x':
                xnum += 1
                ynum += 1
                Pos += 1
        if xnum == ynum and xnum % 2 == 0:
            return Neg // 2 + Pos // 2 + (Neg % 2 + Pos % 2)

        else:
            return -1


```
