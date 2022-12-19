```
class Solution:
    def myAtoi(self, str: str) -> int:
        s = str.lstrip()  # 去掉字符串左边的空格，如果有的话
        s_len = len(s)
        
        if s_len ==0 or s[0] not in '0123456789+-':
            return 0
        
        index = 1
        while index<s_len and s[index].isdigit():
            index += 1
        if index == 1 and s[0] in '+-':
            return 0
        
        result = int(s[:index])
        if result<0:
            return max(-2**31, result)
        else:
            return min(2**31-1, result)
```