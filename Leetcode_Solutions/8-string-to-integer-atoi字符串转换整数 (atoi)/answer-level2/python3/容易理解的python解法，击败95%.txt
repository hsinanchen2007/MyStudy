```
class Solution:
    def myAtoi(self, str: str) -> int:
        numdic = {'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9}
        i = 0
        # 跳过前面的空白
        while i < len(str) and str[i] == ' ':
            i += 1
        # 判断异常转换情况
        if i >= len(str) or (str[i] not in numdic and str[i] not in ('+','-')):
            return 0
        # 判断正负性
        sign = 1
        if str[i] == '-':
            sign = -1
            i += 1
        elif str[i] == '+':
            i += 1
        # 提取数
        num = 0
        boundry = (1<<31)-1 if sign > 0 else 1<<31
        # 注意先判断索引，以防越界
        while i < len(str) and str[i] in numdic:
            num = num *10 + numdic[str[i]]
            i += 1
            if num > boundry:
                return sign * boundry
        return sign * num
```
