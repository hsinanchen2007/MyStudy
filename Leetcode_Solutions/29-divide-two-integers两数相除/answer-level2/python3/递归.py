### 解题思路
1. 先确定需返回结果的正负号
2. 定义输出变量i = 1， 用divisor += divisor; i += i使divisor快速逼近dividend, 并记录下一共累加了多少次初始的divisor
3. 当divisor>dividend后，使divisor和i都减半，然后用dividend与divisor的差值递归调用这个函数，并与将结果与i相加
4. 最后判断结果有没有越界
### 代码

```python3
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        flag = False
        if dividend > 0 and divisor > 0:
            pass
        elif dividend > 0 and divisor < 0:
            divisor = -divisor
            flag = True
        elif dividend < 0 and divisor > 0:
            dividend = -dividend
            flag = True
        else:
            dividend = -dividend
            divisor = -divisor
        if dividend == 0 or dividend < divisor:
            return 0
        if dividend == divisor:
            if flag:
                return -1
            else:
                return 1
        i = 1
        temp = divisor
        while divisor < dividend:
            last_divisor = divisor
            divisor += divisor
            last_i = i
            i += i
        divisor -= last_divisor
        i -= last_i
        i += self.divide(dividend-divisor, temp)
        if flag:
            if -i >= 2147483648:
                return -2147483647
            return -i
        else:
            if i >= 2147483648:
                return 2147483647
            return i
        
```