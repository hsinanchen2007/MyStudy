
### 代码

```python3
class Solution:
    def strToInt(self, str1: str) -> int:
        # 为空， 直接返回
        if not len(str1):
            return 0
        
        # 去掉开头的空格
        tmp_idx = 0
        for elem in str1:
            if elem == ' ':
                tmp_idx += 1
            else:
                break
        
        # 将 + - 符号 和 数字保存在str_temp中
        str_temp = ''
        if tmp_idx < len(str1) and str1[tmp_idx] in ('+', '-'):
            str_temp += str1[tmp_idx]
            str_temp = str_temp + self.cache_char(tmp_idx+1, len(str1), str1)
        else:
            str_temp = self.cache_char(tmp_idx, len(str1), str1)
        
        if str_temp:
            # 将 str_temp 字符串 转换为 int
            if str_temp[0] == '+':
                val = self.c_num(str_temp[1:])
            elif str_temp[0] == '-':
                val = -(self.c_num(str_temp[1:]))
            else:
                val = self.c_num(str_temp)
            
            # 越界判断
            if val > 2 ** 31 - 1:
                return 2 ** 31 - 1
            if val < -(2 ** 31):
                return -(2 ** 31)
            return val
        return 0

    # 中间保存 字符串 中的  数字
    def cache_char(self, start, size, s):
        num_dict = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}
        a = ''
        for i in range(start, size):
            if s[i] in num_dict:
                a += s[i]
            else:
                return a
        return a

    # 字符串转整数
    def c_num(self, num_str):
        res = 0
        for elem in num_str:
            res = res * 10 + int(elem)
        return res
```