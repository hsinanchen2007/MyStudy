### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def lastRemaining(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        f = 0
        for i in range(2, n + 1):
            f = (m + f) % i
        return f

```