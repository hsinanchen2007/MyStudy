### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def printNumbers(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        m=10
        for _ in range(n-1):
            m=m*10
        s = []
        for i in range(1,m):
            s.append(i)
        return s
```