```
"""
边界条件：

数据在计算过程中上下溢出

空字符串

只有正负号

有无正负号

正负号是否会出现在非法的地方(如第二位)

非法字符出现在正常数字块之后
"""

class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        INT_MAX = pow(2,31)-1
        INT_MIN = -pow(2,31)
        str = str.strip()
        if not str:
            return 0
        sign = 1
        s=0
        for index,i in enumerate(str):
            if index == 0 and i == "+":
                sign = 1
            elif index == 0 and i == "-":
                sign = -1
            elif i<="9" and i>="0":
                if s > INT_MAX//10 or (s == INT_MAX//10 and i>"7"):
                    if sign == 1:
                        return INT_MAX
                    else:
                        return INT_MIN
                s=s*10+int(i)   
            else:
                break
        s = s*sign
        return s


```
