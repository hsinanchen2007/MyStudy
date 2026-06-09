### 解题思路
位运算是计算机最底层的运算方式，可以用来实现加减乘除

### 代码

```python3
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        shang = 0
        flag = (dividend>0) ^ (divisor>0)
        dividend = abs(dividend)
        divisor = abs(divisor)
        while dividend >= divisor:
            divisor_tmp = divisor
            shang_tmp = 1
            while dividend>=divisor_tmp:
                divisor_tmp<<=1
                shang_tmp <<=1
            shang_tmp >>=1
            divisor_tmp>>=1
            dividend -= divisor_tmp
            shang += shang_tmp
        if flag:
            shang = -shang
        shang = shang if shang < 2**31-1 else 2**31-1
        return shang

```