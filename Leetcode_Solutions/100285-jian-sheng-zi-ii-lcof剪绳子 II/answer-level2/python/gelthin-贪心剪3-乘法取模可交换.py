### 解题思路
乘法和取模运算可以交换:

(a*c)%b = (a+a+...+a)%b = (a%b +... +a%b)%b = (a%b)*c%b

故可以在计算过程中不断进行取模运算，虽然 python3 int 可以存储无穷大的数。


### 代码

```python3
class Solution:
    def cuttingRope(self, n: int) -> int:
        if n == 2:
            return 1
        if n == 3:
            return 2
        if n == 4:
            return 4
        res = 1
        while n>4:
            res *= 3
            res = res%(10**9+7)  # 可以边做乘法，边取模，取模运算和乘法可以交换顺序
            n -= 3
        res *= n
        return res%(10**9+7)
```