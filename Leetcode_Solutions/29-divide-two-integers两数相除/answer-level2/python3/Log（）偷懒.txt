### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        i =0
        if dividend > 0 and divisor < 0 or dividend <0 and divisor > 0:
            i = -1
        if abs(dividend) < abs(divisor):
            return 0
        divisor = -abs(divisor)
        if dividend != -2*31:
            dividend = -abs(dividend)
            b = int(math.exp(math.log(-dividend)-math.log(-divisor)))
        else:
            dividend = 2**31 - 1
            b = int(math.exp(math.log(dividend+1)-math.log(-divisor)))
        if i == -1 :
            return -b
        else:
            return min(b,2**31-1)


        

```