使用进位加法原理进行计算
先转换两个字符串到相同长度，用变量 summ 存储进位值（ 0 表示进位，1 不进位），然后从后到前依次计算
感觉写出来也没有很长，啦啦啦

```python
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        if len(a) < len(b): 
            a, b = b, a
        n = len(a)
        b = '0'*(n - len(b)) + b    #补齐 b 不足的位为 0
        result = ''
        summ = 0    #进位值
        for i in range(n):
            a_1 = int(a[-i-1])
            b_1 = int(b[-i-1])
            result = str((a_1 + b_1 + summ) % 2) + result    #当前位数相加模 2 ，链接更小位数的值
            summ = (a_1 + b_1 + summ) // 2    #当前位数之和整除二，得到下一位运算的进位值
        
        if summ == 1:    #判断最高位是否需要进位
            result = '1' + result
        return result
```