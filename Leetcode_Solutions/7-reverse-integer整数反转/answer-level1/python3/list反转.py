```
class Solution:
    def reverse(self, x: int) -> int:
        if x >= (-2)**31 and x <= (2**31)-1: #判断范围
            minus = "+" #正负符号记录
            num = str(x) 
            new = []
            i = 0
            while i < len(num):#加进list
                new.append(num[i])
                i+=1
            if x < 0:#如果是负数，去掉list里符号，记录在minus里
                minus = "-"
                new.remove('-')
            s = len(new)-1
            output = ''
            while s >= 0:#倒序组成output
                if new[s] == 0:
                    pass
                    s-=1
                else:
                    output = output + new[s]
                    s-=1
            if minus == "-":#添加负号
                output = minus + output
            
            output = int(output)
            if output >= (-2)**31 and output <= (2**31)-1:#检查结果是否符合范围
                return output
            else: 
                return 0
        else:
            return 0
```
