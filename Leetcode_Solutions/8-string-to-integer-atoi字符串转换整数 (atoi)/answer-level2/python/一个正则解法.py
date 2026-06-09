class Solution:
    def myAtoi(self, str: str) -> int:
        import re    #  导入 re库(正则表达式)
        sr = str.lstrip()   # 截掉左边的空格
        _str = re.findall('[+-]{0,1}[0-9]*',sr)  # 匹配 一个 +-号后面跟着数字(数字是贪婪匹配)
        if (_str[0] == '' )or( _str[0] == '+' )or( _str[0] == '-'):  
            return 0
        elif int(_str[0])> 2**31 -1:
            return 2**31 -1
        elif int(_str[0]) < -2**31:
            return -2**31
        else:
            return int(_str[0])

一个简单的python写法,应该还可以优化