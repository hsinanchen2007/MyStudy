#### 说明：
 - Python需要手工补充题设对应的max_int
#### 复杂度分析：
 - 时间复杂度：$O(logN)$
 - 空间复杂度：$O(1)$
```Python
class Solution(object):

    def toHex(self, num: int) -> str:
        # 如果小于零，则进行补码
        max_int = 0xffffffff + 0x00000001
        if num < 0:
            num += max_int

        hex_convert = ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f')
        divisor = 0x00000010        # 除数
        result = ''                 # 结果

        # do...while
        # 按照运算规则取模，并构造结果字符串
        quotient, remainder = divmod(num, divisor)
        result = hex_convert[remainder] + result
        while True:
            quotient, remainder = divmod(quotient, divisor)
            if not (quotient == remainder == 0):
                result = hex_convert[remainder] + result
            else:
                break

        return result
```