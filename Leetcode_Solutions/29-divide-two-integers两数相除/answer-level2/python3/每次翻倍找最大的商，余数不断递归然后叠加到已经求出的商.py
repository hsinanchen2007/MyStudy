执行用时 :32 ms, 在所有 python3 提交中击败了97.41%的用户
内存消耗 :12.7 MB, 在所有 python3 提交中击败了99.52%的用户

### 解题思路
此处撰写解题思路
不断循环翻倍加大除数，否则会超时
### 代码

```python3
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        dividend_abs=abs(dividend)
        divisor_abs=abs(divisor)
        res=0
        if dividend==-(2**31) and divisor==-1:
            return 2**31-1
        if divisor==1:
            return dividend
        if divisor==-1:
            return -dividend

        def div(a,b):
            tb=b
            count=1
            if a<b:
                return 0
            while a>=(tb+tb):
                count=count+count
                tb=tb+tb
            return count+div(a-tb,b)
        res=div(dividend_abs,divisor_abs)
        if (dividend>0 and divisor<0) or (dividend<0 and divisor>0):
            res=-res
        return res
```