### 解题思路
此处撰写解题思路

### 代码

```python
import math
class Solution(object):
    def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        len_1 = len(str1)
        len_2 = len(str2)
        if len_1 == 0 or len_2 == 0 or str1 + str2 != str2 + str1:
            return ''
        if len_1 < len_2:
            temp = str1
            str1 = str2
            str2 = temp
        def str_mod(s1, s2):
            ind = 0
            len_2 = len(s2)
            while s1[ind: ind + len_2] == s2:
                ind += len_2
            return s1[ind:]
        res = str_mod(str1, str2)
        while res != '':
            str1 = str2
            str2 = res
            res = str_mod(str1, str2)
        return str2

```