另一个答案里有解释原理
```
class Solution:

    def divide(self, dividend: int, divisor: int) -> int:

        f, dd, dr = (dividend >= 0) ^ (divisor >= 0), abs(dividend), abs(divisor)

        def rf(dd, dr):
            if dd < dr: return dd, 0
            dd, r = rf(dd, dr << 1)
            return (dd-dr, (r << 1)+1) if dd >= dr else (dd, r << 1)

        left, ans = rf(dd, dr)
        return -ans if f else 2**31-1 if ans > 2**31-1 else ans
```
