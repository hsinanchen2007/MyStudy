### 解题思路
暴力列举可能的情况，设置三个flag 
flag：记录正负号
sign: 用来记录前面是否已经出现过正负号，如果有则之后遇到正负号就跳出循环 应对符号连续出现的情况
数：用来记录前面是否已经出现过数字，如果有则之后遇到空格就跳出循环 应对数字不连续中间有空格的情况
### 代码

```python
class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        length = len(str)            
        flag = 1
        num = 0
        sign = 0
        shu = 0
        for i in range(length):
            if str[i] == ' ' and shu == 0:
                continue
            if str[i] == ' ' and shu == 1:
                break
            if str[i]<'0' or str[i]>'9':
                if sign == 1 or shu == 1:
                    break

                if str[i] != '-' and str[i] != '+':   
                    break

                if str[i] == '-' and sign == 0:
                    flag = -1
                    sign = 1
                    shu = 1

                if str[i] == '+' and sign == 0:
                    flag = 1
                    sign = 1
                    shu = 1

            if  str[i]>='0' and str[i]<='9':
                num = num * 10 + int(str[i])
                shu = 1
        if num * flag >= -2**31 and num * flag < 2**31:
            return num * flag
        elif num * flag < -2**31:
            return -2**31
        else:
            return (2**31-1)

            

```