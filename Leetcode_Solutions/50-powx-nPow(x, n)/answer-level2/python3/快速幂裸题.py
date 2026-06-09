裸快速幂，特判等于 0 和小于 0 的情况即可。

```python
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0: 
            return 1
        flag = False
        if n < 0:
            n = -n
            flag = True
        res = 1
        while n > 0:
            if n & 1 == 1:
                res *= x
            x *= x    
            n >>= 1
        return res if not flag else 1 / res
```