这道题，大略的功能是不难实现的， 主要是要考虑很多特殊的情况，这一定要事先都考虑到位，不然就像我一样，几分钟写好，然后提交无数次，对错误的情况缝缝补补，最后花了快一个小时，才通过。
```python
class Solution:
    def myAtoi(self, str: str) -> int:
        if len(str) == 0: # 空字符串的特殊情况
            return 0
        # 寻找第一个非空格字符的位置
        for i in range(len(str)):
            if str[i] != ' ':
                break
        start = i

        if str[start] == '-': # 第一个为负号或正号，从下一个字符开始寻找数字
            signal = -1
            start += 1
        elif str[start] == '+':
            signal = 1
            start += 1
        elif not str[start].isdigit(): # 第一个既不是正负号，也不是数字，返回0
            return 0
        else:
            signal = 1 # 第一个是数字，从这个字符开始找数字
        
        if start == len(str):return 0 # 预防首次发现正负号是在最后一位，比如'+','    +'等情况

        if not str[start].isdigit():return 0  # 预防正负号后一位出现的是符号的情况，比如'+-2'等情况
        # 开始找数字
        for j in range(start, len(str)):
            if not str[j].isdigit():
                break
        end = j # start之后，第一个不是数字的字符位置end;
        # 也有可能start之后全是数字，比如"-42";
        # 通过str[end]是不是数字判断,是的话，在取数字的时候，要把end这个位置的数字给加上。
        res = signal * int(str[start:end + 1]) if str[end].isdigit() else signal * int(str[start:end])
        if res > 2147483647:
            return 2147483647
        if res < -2147483648:
            return -2147483648
        return res
```
