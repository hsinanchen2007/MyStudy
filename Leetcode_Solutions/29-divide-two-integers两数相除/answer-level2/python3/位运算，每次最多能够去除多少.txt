### 解题思路

直接一个一个减会超时，可以使用移位操作，每次看最多能够减掉多少

时间复杂度`O(1)` 空间复杂度`O(1)`


### 代码

```python3
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend == 0:
            return 0
        flag = False
        if dividend < 0 and divisor > 0 or dividend > 0 and divisor < 0:
            flag = True
        dividend = abs(dividend)
        divisor = abs(divisor)

        _di = divisor
        res = 0
        while dividend >= _di:
            tmp = 1
            a = _di
            while dividend >= a:
                a = a << 1
                tmp = tmp << 1
            a = a >> 1
            tmp =tmp >> 1
            dividend -= a
            res += tmp
        if flag:
            if res > 1 << 31:
                return (1 << 31) - 1
            return -1 * res
        else:
            if res > (1 << 31) - 1:
                return (1 << 31) - 1
            return res
```