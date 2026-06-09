```
class Solution:
    def brokenCalc(self, X: int, Y: int) -> int:
        return X-Y if X>=Y else (1+(self.brokenCalc(X,Y+1) if Y&1  else self.brokenCalc(X,Y//2)))
```
