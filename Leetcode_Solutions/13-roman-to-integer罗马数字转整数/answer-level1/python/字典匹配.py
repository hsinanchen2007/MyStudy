### 解题思路

### 代码

```python
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        trans1 = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
        trans2 = {"IV":4, "IX":9,"XL":40, "XC":90, "CD":400, "CM":900}
        res = 0
        string = s
        for key in trans2:
            if key in string:
                res += trans2[key]
                string= string.replace(key, "")
        for key in trans1:
            if key in string:
                res += trans1[key] * string.count(key)
        return res
```