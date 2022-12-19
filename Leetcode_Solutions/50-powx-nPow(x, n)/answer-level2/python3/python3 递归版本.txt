递归版本：
1) 递归基础条件：
    n = 1：返回x
2) n为奇数，则x*myPow(x, n - 1)
3) n为偶数， 则 myPow(x, n // 2) ** 2
```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return float(1)
        if n < 0:
            x = 1 / x
            n = - n
        # 递归的返回条件
        if n == 1:
            return x
        # n 为奇数次幂
        if n & 1:
            return x * self.myPow(x, n - 1)
        else:
            # n 为偶数次幂
            return self.myPow(x, n // 2) ** 2
```