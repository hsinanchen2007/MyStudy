### 解题思路
猜，就猜嘛。
猜小了小的就是下限，猜大了大的就是上限，直到上下限差为1，下限就是要的值

### 代码

```python3
class Solution:
    def mySqrt(self, x: int) -> int:
        import random as rd
        L = 0
        R = x//2+1
        while L < R:
            rint = rd.randint(L, R)
            if rint**2 <= x:
                L = rint
                if R-L==1:
                    return L
            elif rint**2 > x:
                R = rint
```