```python
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        a, b, r, t = abs(dividend), abs(divisor), 0, 1
        while a >= b or t > 1:
            if a >= b: r += t; a -= b; t += t; b += b
            else: t >>= 1; b >>= 1
        return min((-r, r)[dividend ^ divisor >= 0], (1 << 31) - 1)
```
- 让被除数不断减去除数，直到不够减。每次减完后除数翻倍，并记录当前为初始除数的几倍（用 t 表示倍数 time），若发现不够减且 t 不为 1 则让除数变为原来的一半， t 也减半
- a 为被除数绝对值，b 为除数绝对值，r 表示 result，t 表示当前除数对于原始除数的倍数
- a << b 相当于 `a * 2**b`，a >> b 相当于 `a // 2**b`
- 异或操作 ^ 可以判断俩数字是否异号