### 解题思路
这道题如果判断重合是比较麻烦的，这时候我们可以转换思路，来判断两个矩形不重合，剩下的情况就是重合了。

### 代码

```python
class Solution(object):
    def isRectangleOverlap(self, rec1, rec2):
        """
        :type rec1: List[int]
        :type rec2: List[int]
        :rtype: bool
        """
        a, b, c, d = rec1
        p, q, m, n = rec2
        if q >= d or n <= b or m <= a or p >= c:
            return False
        return True
```