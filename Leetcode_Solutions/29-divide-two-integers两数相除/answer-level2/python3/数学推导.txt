假设被除数为x, 除数为y, 余数为r 。运行下面的循环最终结果为 x - ny = r，如果r>y则再次运行改循环直到r<y为止。
```
while dividend >= divisor and dividend - factor >= 0:
            factor += divisor
            i += 1
            dividend -= factor
            count += i
```

每次运行上面的循环时,商为count,即从1加到n。由于除数一直在增大，因此循环时间不会太长。完整代码如下
```
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if (divisor > 0 and dividend > 0) or (divisor < 0 and dividend < 0):
            flag = True
        else:
            flag = False

        result, remainder = self.predivide(dividend, divisor)
        while remainder >= abs(divisor):
            post_result, remainder = self.predivide(remainder, divisor)
            result = result + post_result
        return self.stackoveflow(flag, result)

    def predivide(self, dividend, divisor):
        dividend = abs(dividend)
        divisor = abs(divisor)
        count = 0
        i = 0
        factor = 0
        while dividend >= divisor and dividend - factor >= 0:
            factor += divisor
            i += 1
            dividend -= factor
            count += i
        if dividend < 0:
            count -= 1
        return count, dividend

    def stackoveflow(self, flag, result):
        int_max = 2147483647
        int_min = -2147483648
        if flag:    # positive result
            return min(int_max, result)
        else:      # negative result
            return max(int_min, -result)
```