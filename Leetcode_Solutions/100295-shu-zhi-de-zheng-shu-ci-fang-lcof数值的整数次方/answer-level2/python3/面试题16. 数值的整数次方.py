### 解题思路
递归，当幂为奇数时，(x*x)^(n-1)/2 * (x*x)^(n-1)/2 * x
偶数时：(x*x)^n/2 * (x*x)^n/2

### 代码

```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            x = 1/x
            n = -n
        if n == 0:
            return 1
        if n == 1:
            return x
        if n % 2 == 0:            
            return self.myPow(x*x, n/2)
        else:
            return self.myPow(x*x, (n-1)//2) * x
```