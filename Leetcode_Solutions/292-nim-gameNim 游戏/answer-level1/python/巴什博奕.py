### 解题思路
试了两种方式，取余更快点～

### 代码

```python
class Solution(object):
    def canWinNim(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # m = 3
        # return n % (m+1) !=0

        return n & 3
```