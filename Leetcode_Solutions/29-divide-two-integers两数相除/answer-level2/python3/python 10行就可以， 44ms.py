
```
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        quotient = abs(divisor) == 1 and abs(dividend) or 0  # 表达式 and value1 or value2 等价于 表达式?value1:value2
        flag = (dividend ^ divisor) < 0 and True or False
        dividend, divisor = abs(dividend), abs(divisor)
        if not quotient:  # 如果quotient不为0，说明divisor=1则不用计算
            for i in range(31, -1, -1):
                if (dividend >> i) >= divisor:  # y >> x 等价于 y // 2**x
                    quotient += 1 << i  # y << x 等价于 y * 2**x
                    dividend -= divisor << i
                    if dividend < divisor:
                        break
        return flag and max(-2**31, -quotient) or min(2**31-1, quotient)
```
