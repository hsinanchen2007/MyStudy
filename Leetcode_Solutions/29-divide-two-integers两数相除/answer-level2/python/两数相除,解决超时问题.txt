### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        flag = True  # 用于判断最后结果的符号
        if (dividend>0 and divisor<0) or (dividend<0 and divisor>0):
            flag = False
        n = 0
        dividend = abs(dividend)
        divisor = abs(divisor)
        while dividend >= divisor:
            cur_divisor, count = divisor, 1
            while dividend >= cur_divisor:
                dividend -= cur_divisor
                n += count
                count <<= 1
                cur_divisor <<= 1
        return min(n,2**31-1) if flag else max(-n,-2**31)
```