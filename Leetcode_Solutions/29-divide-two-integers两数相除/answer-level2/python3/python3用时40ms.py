```
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # 如果被除数是0，返回0
        if dividend == 0:
            return 0
        # 记录负号，统一成正数计算
        sign = (dividend > 0) ^ (divisor > 0)
        a = abs(dividend)
        b = abs(divisor)
        ans = 0
        # 以下为计算过程，通过阶乘来减少计算时间，最复杂的情况为m**n-1//m的情况
        while a >= b and ans < 2**31:
            # 如果除数为1
            if b == 1:
                ans = a
                break
            c, d = ok(a,b)
            # a减去返回来的部分
            a -= d
            # 答案也加上
            ans += 2**c
        if sign:
            return max(-ans,-2**31)
        else:
            return min(ans,2**31-1)


# 算被除数的阶乘最大能到多少
# 其实是a>=b*(2**count),最大的count，不能用乘法，就用b+b好了
# 例如a = 27,b = 3,第一次输入，27>3*(2**3),此时count=3最大，输出时b = 24
def ok(a: int, b: int):
    count = 0
    while a >= b+b:
        b += b
        count += 1
    return count, b
```
