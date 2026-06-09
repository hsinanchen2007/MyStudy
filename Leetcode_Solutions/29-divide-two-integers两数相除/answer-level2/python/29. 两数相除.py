### 解题思路
用循环减法代替除法，减数迭代增大，减少循环次数
`PS: 因为环境中只存储32位有符号整数，其数值范围是 [−2^31,  2^31 − 1]，所以如果把所有数都转为正数的话，−2^31取反后即会溢出， 故将所有的数字转换为负数进行计算，则没有溢出风险`

### 代码

```python3
class Solution:
    def oppo(self, x):
        # 取相反数函数，避免使用‘-’，也算乘法
        # 取反加一，相当于求相反数
        return ~x + 1

    def divide(self, dividend: int, divisor: int) -> int:
        res = 1  # 记录结果(无符号)
        sign = 1  # 表示结果正负性（符号）
        # 如果dividen和divisor只有一个大于零，则sign为负；否则为正
        if dividend > 0:
            dividend = self.oppo(dividend)
            sign = self.oppo(sign)
        if divisor > 0:
            divisor = self.oppo(divisor)
            sign = self.oppo(sign)
        
        a, b = dividend, divisor
        # 如果除数小于被除数，则结果肯定为0.（注意此时两者都是负数）
        if b < a:
            return 0
        # 通过减法循环，计算除法结果
        a = a - b  # 先计算一次，对应res=1的初始值
        while a <= b:  # 循环过程中不断增加除数的值，减少循环次数，避免超时
            res += res
            b += b
            a -= b
        # 循环结束后，可能存在未处理完的情况，比如 10 - 1 = 9，9 - 2 = 7，7 - 4 = 3，3 - 8 = -5 < 1
        # 它就走出了 while 循环，但是 3 本来还可以减 3 次 1，所以只要再递归
        res = res + self.divide(dividend-b, divisor)

        # 处理可能的溢出情况
        if res == 2**31:
            if sign == 1:
                return 2**31 - 1
            else:
                return -2**31
        # 根据sign调整结果的正负性
        else:
            if sign == 1:
                return res
            else:
                return self.oppo(res)
        




```