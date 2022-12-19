### 解题思路
参考
>详细通俗的思路分析，多解法
>windliang

python 解法
考虑溢出，考虑边界，更加简洁


### 代码

```python3
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # 相反数
        def opposite(x):
            return ~x+1

        # 边界
        if dividend == -2147483648 and divisor==-1:
            return 2147483647

        ans = -1
        sign = 1   
        # 采用负数是因为-2147483648无法转换为正数
        if dividend >0:
            dividend = opposite(dividend)
            sign = opposite(sign)
        if divisor >0:
            divisor = opposite(divisor)
            sign = opposite(sign)
        org_dividend = dividend
        org_divisor = divisor
        
        # 归
        if dividend > divisor:
            return 0

        dividend -= divisor
        while dividend <= divisor:
            ans += ans
            dividend -= divisor
            divisor += divisor
        # 此时ans负数累加，但是传进去的数是两个负数，返回的是正数，所以取反
        ans = ans + opposite(self.divide(org_dividend - divisor,org_divisor))

        return ans if sign <0 else opposite(ans)
        
        
```