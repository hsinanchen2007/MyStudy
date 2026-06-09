    分情况讨论，按以下步骤直接上手转换即可。
    时间复杂度O(n), 空间复杂度O(1)。
```
class Solution:
    def myAtoi(self, s: str) -> int:
        # Case 1. 空串  ==>  直接返回0
        if not s:
            return 0
        i, length = 0, len(s)
        INT_MIN, INT_MAX = -2147483648, 2147483647
        sign, res = 1, 0
        # Case 2. 串左侧有空白字符(‘ ’)  ==>  过滤之
        while i < length and s[i] == ' ':
            i += 1
        # Case 3. 过滤掉空白字符后到达串尾或者出现无效字符  ==>  返回0
        if i == length or not ((s[i] >= '0' and s[i] <= '9') or s[i] == '+' or s[i] == '-'):
            return 0
        # Case 4. 第一个有效字符可能为’-’, ’+’, 数字字符, 根据此字符确定转换后整数的符号(sign = -1表示负数, sign = 1表示正数)
        if s[i] == '-':
            sign = -1; i += 1
        else:
            sign = 1
            if s[i] == '+': i += 1
        # Case 5. 转换过程, 注意溢出的处理, 将连续出现的数字字符转换为一个正整数
        while i < length and s[i] >= '0' and s[i] <= '9':
            res = res * 10 + (ord(s[i]) - 48)
            i += 1
            if sign == -1 and res > -INT_MIN: return INT_MIN
            if sign == 1 and res > INT_MAX: return INT_MAX
        # Case 6. 最终, sign * res即为所求
        return sign * res
```
