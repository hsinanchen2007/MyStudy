```python
class Solution:
    def myPow(self, x, n, r=1) -> float:
        x, n = n < 0 and 1 / x or x, abs(n)
        return self.myPow(x * x, n // 2, r * (not n % 2 or x)) if n else r
```
- 尾递归 O(logN) 解法
- x^4 正常计算过程：x * x * x * x，O(N)
- 优化后：(x**2)**2，O(logN)