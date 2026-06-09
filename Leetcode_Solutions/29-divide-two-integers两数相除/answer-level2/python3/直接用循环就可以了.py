### 解题思路
此处撰写解题思路

### 代码

```python3

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if abs(divisor) > abs(dividend):
            return 0
        sign_flag = False  # 无符号

        if dividend > 0 and divisor < 0 or dividend < 0 and divisor > 0:
            sign_flag = True
        dividend = abs(dividend)
        divisor = abs(divisor)
        divisor_old = divisor
        divisor_new = 0
        return_result = 0
        while True:
            result = 0
            count = 0
            while divisor <= dividend:
                result = 2 ** count
                count += 1
                divisor_new = divisor
                divisor += divisor
            if result != 0:
                return_result += result
                dividend = dividend - divisor_new
                divisor = divisor_old
            else:
                break
        if sign_flag:
            return_result = -return_result
        return return_result if -2 ** 31 <= return_result <= 2 ** 31 - 1 else 2 ** 31 - 1

```