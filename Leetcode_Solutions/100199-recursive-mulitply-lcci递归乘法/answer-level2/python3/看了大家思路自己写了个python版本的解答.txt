```
class Solution:
    def multiply(self, A: int, B: int) -> int:
        if A==1:
            return B
        if A==0:
            return 0
        return self.multiply(A>>1,B<<1)+self.multiply(A%2,B)
```
