### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        len1 = len(str1)
        len2 = len(str2)
        def gcd(m, n):
            if n == 0:
                return m
            else:
                return gcd(n, m % n)
        gcd_num = gcd(len2, len1)

        if str1 + str2 == str2 + str1:
            return str1[:gcd_num]
        else:
            return ""

```