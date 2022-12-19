```
class Solution:
    def brokenCalc(self, X: int, Y: int) -> int:
        if X >= Y:
            return X-Y
        
        ret = 0
        while X < Y:
            Y = (Y // 2) if (Y % 2 == 0) else (Y + 1)
            ret += 1
        
        return ret + X - Y
```
