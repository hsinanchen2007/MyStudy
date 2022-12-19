```python
def divide(self, dividend: int, divisor: int) -> int:
    if dividend == 0: return 0
    flag = (dividend > 0 and divisor < 0) or (dividend < 0 and divisor > 0)  # ^
    dividend = dividend if dividend > 0 else -dividend  # abs
    divisor = divisor if divisor > 0 else -divisor  # abs
    res = 0
    if divisor == 1:
        res = dividend  # directly to get the result
    else:
        while dividend >= divisor:
            cnt = 1
            temp = divisor
            while dividend >= (temp << 1):
                temp = temp << 1
                cnt = cnt << 1
            dividend -= temp
            res += cnt
    if res > 2 ** 31 - 1:  # out of range
        return -2 ** 31 if flag else 2 ** 31 - 1
    else:
        return -res if flag else res
```