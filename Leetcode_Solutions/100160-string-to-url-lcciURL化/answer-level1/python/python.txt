### 解题思路
又是一道阅读理解题

### 代码

```python
class Solution(object):
    def replaceSpaces(self, S, length):
        """
        :type S: str
        :type length: int
        :rtype: str
        """
        return "%20".join(S[:length].split(" "))
```