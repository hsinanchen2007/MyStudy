这道题的难点在于理清各种限制条件，先看清题意再做题。
注意点：
    1. 找到第一个非空字符
    <\br>    1. 如果第一个非空字符是‘+‘，’-’符号则找后面`连续`的数字
    <\br><\br>      1. 如果’+’，‘-‘之后内容为空或非数字，则返回0
    <\br><\br>      2. 如果`连续`数字后出现其他的符号，则舍弃后面的所有字符。
    <\br>    2. 如果第一个非空字符是除正负号、数字外的其他字符，则返回0
    2. 结果数值范围为 $[−2^{21},  2^{31} − 1] 超出边界的返回对应的边界值。

python实现：
    
```
import math


def myAtoi(str):
    str_list = []
    for i in str:
        if i == ' ' and len(str_list)==0:
            continue
        else:
            str_list.append(i)
    neg = 1
    res = []
    if len(str_list) == 0:
        return 0
    if str_list[0] == '-':
        neg = -1
        str_list = str_list[1:]
    elif str_list[0] == '+':
        neg = 1
        str_list = str_list[1:]
    if len(str_list) == 0:
        return 0
    if ord(str_list[0]) < 48 or ord(str_list[0]) > 57:
        return 0
    for s in str_list:
        if len(res)!=0 and (ord(s) < 48 or ord(s) > 57):
            break
        int_s = int(s)
        res.append(s)

    res = ''.join(res)
    if res == '':
        return 0
    res = int(res)
    res = neg * res
    up = math.pow(2, 31) - 1
    down = -math.pow(2, 31)
    if res > up:
        return int(up)
    if res < down:
        return int(down)
    return res

```
