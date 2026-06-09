### 解题思路
本题有两个关键点，**一个是判断是否存在这样的子串**，**另一个是存在的话，怎么求这个子串**。
- 对于第一点，有两种方法：
1. 第一是先求出两个字符串的长度的最大公约数，然后将待定子串拼接起来看是否和原字符串相同。字符串拼接使用了乘法。
2. 第二种方法是官方题解中的数学方法，不得不说真的牛皮。str1+str2==str2+str1.
- 对于第二点，就是求两个字符串的长度的最大公约数。这里涉及最大公约数的求法。辗转相除或者辗转相减，或者枚举法。

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
        l1 = len(str1)
        l2 = len(str2)
        while l1!=l2:
            if l1>l2:
                l1 = l1-l2
            else:
                l2 = l2-l1
        common = str1[0:l1]
        if str1+str2 == str2+str1:
            return common
        else:
            return ''


```