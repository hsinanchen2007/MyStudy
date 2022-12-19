
```
# -*- coding: utf-8 -*-

# Author: Cynthia

"""
    题目分析: 忽略首部空格, 若首字符非+/-/数字, 返回0; 若数字部分后面还跟着非数字, 忽略;
    若超过-2^31~2^31-1, 负数返回-2^31, 正数返回2^31-1
"""
import re


class Solution:

    def myAtoi(self, str: str) -> int:
        # 把符合条件的数字部分先摘出来
        s = re.match(r"[+-]?[0-9]+", str.strip())
        if not s: return 0
        s = s.group(0)
        # 有负号则置flag=-1
        flag = -1 if s[0] == '-' else 1
        # 截断符号部分
        s = s[1:] if s[0] in {'+', '-'} else s

        # 设置最小最大范围, 在小一位的时候去比较, 不能算完再比
        # 因为如果计算机真是32位, 算完再比是不可能超限的, 已经截断了
        INT_MIN, INT_MAX = -2**31, 2**31-1
        p_min, q_min = int(INT_MIN/10), INT_MIN-int(INT_MIN/10)*10
        p_max, q_max = int(INT_MAX/10), INT_MAX-int(INT_MAX/10)*10

        ans = 0
        for i in s:
            # 确保计算完之后不超限再去计算
            if ans < p_min or (ans == p_min and flag*int(i) < q_min):
                return INT_MIN
            if ans > p_max or (ans == p_max and flag*int(i) > q_max):
                return INT_MAX

            ans = ans*10+flag*int(i)

        return ans


s = Solution()
print(s.myAtoi("+-2"))
```
