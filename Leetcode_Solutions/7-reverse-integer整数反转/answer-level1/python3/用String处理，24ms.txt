先判断是否为负整数，然后将x转换为string做slicing，之后reverse并转为整数，根据sign还原正负号，最后判断是否为32位整数。话不多说，直接上代码：
```python []
class Solution:
    def reverse(self, x: int) -> int:
        sign = x < 0
        x_str = str(abs(x))
        result = int(x_str[::-1])*(-1 if sign else 1)
        return result if -2**31 <= result <= 2**31-1 else 0
```
