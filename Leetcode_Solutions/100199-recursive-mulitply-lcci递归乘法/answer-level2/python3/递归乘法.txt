```python3
class Solution:
    def multiply(self, A: int, B: int) -> int:
        if A == 0 or B == 0:#判断A,B是否等于0，任意等于0则返回0
            return 0
        if A == 1 and B > 1:#判断A=1 B>1的情况，符合条件则返回B
            return B
        if A > 1 and B == 1:#判断A>1 B=1的情况，符合条件则返回B
            return A
        if A > 1 and B > 1:#判断A>1 B>1的情况，每次调用B-1并且加上一次A
            return self.multiply(A,B-1)+self.multiply(A,1)
        
```