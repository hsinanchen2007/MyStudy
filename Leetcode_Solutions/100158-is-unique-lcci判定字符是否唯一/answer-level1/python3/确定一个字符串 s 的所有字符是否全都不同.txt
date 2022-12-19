### 解题思路
依题意，只需判断是否有重复项，无需找出，则直接set去重后与原字符串比较长度即可

### 代码

```python
class Solution(object):
    def isUnique(self, astr):
        """
        :type astr: str
        :rtype: bool
        """
        if len(astr) == len(set(astr)):
            return True
        else:
            return False
```