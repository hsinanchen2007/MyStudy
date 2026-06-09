```
class Solution:
    def myAtoi(self, strs: str) -> int:
        strs = strs.strip() #去空格
        sign = 1
        if len(strs) > 0: #先判断第一个字符，如果是符号，就保留然后去掉
            if strs[0] == "+":
                sign = 1
                strs = strs[1:]
            elif strs[0] == "-":
                sign = -1
                strs = strs[1:]
            elif strs[0] < '0' or strs[0] > '9':
                return 0 
        else:
            return 0
        #接着判断第0个字符
        if len(strs) == 0 or (len(strs) > 0 and strs[0] < '0' or strs[0] > '9'):
            return 0
        #到这里，可以保证现在的字符串至少第0位是数字
        for i in range(len(strs)):
            if strs[i] < '0' or strs[i] > '9':
                if sign == 1:
                    return min(int(strs[:i]) * sign,2**31 -1)
                elif sign == -1:
                    return max(int(strs[:i]) * sign,- 2**31)
                    
        if sign == 1:
            return min(sign * int(strs) ,2**31 -1)
        elif sign == -1: 
            return max(sign * int(strs) ,-2**31)
            
```
