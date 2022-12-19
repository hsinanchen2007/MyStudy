思路: 简单题，主要几个条件都要满足。判断字符串是否有效，以及有效时的第一个开始索引；后面判断第一个开始的是否是符号，以及判断是否终止，以及终止时，数字是否在给定范围内。
与官方求解对比，写的代码比较冗余
```
class Solution:
    def check(self, str):
        for i in range(len(str)):
            if str[i] == ' ':
                continue
            else:
                if str[i] == '-' or str[i] == '+' or str[i]>='0' and str[i] <='9':
                    return i
                else:
                    return -1
        return -1
    def myAtoi(self, str: str) -> int:
        INT_MAX = 2**31 - 1
        INT_MIN = -(2**31)
        res = None
        start = self.check(str)
        if start == -1:
            return 0
        f = 0 
        if str[start] == '-':
            f = -1
            start += 1
        elif str[start] == '+':
            f = 1
            start += 1
        for i in range(start,len(str)):
            if res is None:
                if str[i]>='0' and str[i] <='9':
                    res = int(str[i])
                else:
                    break
            else:
                if str[i]>='0' and str[i] <='9':
                    res = res*10 + int(str[i])
                else:
                    break
        if res is None:
            return 0
        if f == -1:
            res = -1*res
        if res > INT_MAX:
            return INT_MAX
        elif res < INT_MIN:
            return INT_MIN
        return res
                
```
