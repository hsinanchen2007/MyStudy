# 后面再补注释
```
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        count = 1
        Sum = 0
        if (dividend>0 and divisor>0) or (divisor<0 and dividend<0):
            flag = 1
        else:
            flag = 0
        dividend = abs(dividend)
        divisor = abs(divisor)

        while dividend >= divisor:
            dividend = dividend-divisor*count
            while dividend < 0:
                dividend = dividend + divisor*count
                count = count -1
                dividend = dividend - divisor*count
                

            Sum = Sum + count
            count = count + 1
        if flag ==1:
            return  min(Sum,2**31-1)
        else:
            return  max(-Sum,-2**31)
```
