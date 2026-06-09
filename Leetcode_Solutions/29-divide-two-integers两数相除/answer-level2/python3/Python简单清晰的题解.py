```
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend == 0:
            return 0
        if (dividend > 0 and divisor > 0) or (dividend < 0 and divisor < 0):
            sign = 1
        else:
            sign = -1
        val_max = (1 << 31) - 1
        val_min = -(1 << 31)
        if divisor == 1:
            if sign == 1:
                return min(val_max, dividend)
            else:
                return max(val_min, dividend)
        if divisor == -1:
            if sign == 1:
                return min(val_max, -dividend)
            else:
                return max(val_min, -dividend)
        
        a = abs(dividend)
        b = abs(divisor)
        res = 0
        while a >= b:
            temp = b
            count = 1
            while (temp << 1 ) <= a:
                temp <<= 1
                count <<= 1
            a -= temp
            res += count
        if sign == 1:
            return min(val_max, res)
        else:
            return max(val_min, -res)
```
