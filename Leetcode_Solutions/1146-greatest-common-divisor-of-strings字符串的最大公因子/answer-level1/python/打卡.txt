### 解题思路
就是普通的gcd的变形,只不过欧几里得不好使了,得用更相减损术

### 代码

```python
class Solution(object):
    def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """

        def gcd(s1,s2,l1,l2):
            if l2 == 0:return s1
            if s1[:l2] != s2[:]:
                return ""
            if l2>=l1-l2:
                return gcd(s2[:],s1[l2:],l2,l1-l2)
            else :return gcd(s1[l2:],s2[:],l1-l2,l2)
        if len(str1) > len(str2):
            return gcd(str1,str2,len(str1),len(str2))
        else: return gcd(str2,str1,len(str2),len(str1))


```