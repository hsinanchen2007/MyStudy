### 解题思路
菜鸡不会辗转相除，直接用replace函数，如果字符串空了就说明整除了

### 代码

```python
class Solution(object):
    def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        if len(str1)>=len(str2):
            str1, str2 = str2, str1
        for i in range(len(str1),0,-1):
            if len(str1.replace(str1[:i], '')) == 0 and len(str2.replace(str1[:i], '')) == 0:
                return str1[:i]
        return ''
```