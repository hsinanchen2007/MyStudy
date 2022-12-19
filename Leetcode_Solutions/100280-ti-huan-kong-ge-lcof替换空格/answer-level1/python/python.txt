### 解题思路
replace函数替换即可

### 代码

```python
class Solution(object):
    def replaceSpace(self, s):
        """
        :type s: str
        :rtype: str
        """
        return s.replace(" ","%20")
```