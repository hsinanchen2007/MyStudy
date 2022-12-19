### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend == 0:
            return 0
        if divisor == 1:
            return min(max(-2**31, dividend), 2**31-1)
        if divisor == -1:
            return min(max(-2**31, -dividend), 2**31-1)
        if (dividend < 0 and divisor > 0):
            n = -dividend
            m = divisor
            k = -1
        elif (dividend > 0 and divisor < 0):
            n = dividend
            m = -divisor
            k = -1
        elif (dividend > 0 and divisor > 0):
            n = dividend
            m = divisor
            k = 1
        elif (dividend < 0 and divisor < 0):
            n = -dividend
            m = -divisor
            k = 1
        i = 0
        while(n >= 0):
            n = n - m * 2 ** i
            if n < 0:
                n = n + m * 2 ** i
                break
            i = i + 1
        j = 0
        while(n >= 0):
            n = n - m * 3 ** j
            if n < 0:
                n = n + m * 3 ** j
                break
            j = j + 1
        b = 0
        while(n >= 0):
            n = n - m * 5 ** b
            if n < 0:
                n = n + m * 5 ** b
                break
            b = b + 1
        p = 0
        while(n >= 0):
            n = n - m
            p = p + 1
        r = 0
        for l in range(i):
            r = r + 2 ** l
        for l in range(j):
            r = r + 3 ** l
        for l in range(b):
            r = r + 5 ** l
        r = r + (p - 1)
        if k == -1:
            r = -r
        return min(max(-2**31, r), 2**31-1)
```