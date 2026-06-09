```python
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        self.__class__.__getitem__ = lambda self, x: isBadVersion(x)
        return bisect.bisect_left(self, True, 1, n)
```
- 改造当前类的魔法方法getitem以使用内置函数
- 复现二分搜索解法如下：
```python
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        l, h = 1, n
        while l <= h:
            m = (l + h) // 2
            if isBadVersion(m) > m * isBadVersion(m - 1):
                return m
            elif isBadVersion(m):
                h = m - 1
            else:
                l = m + 1
```
- 本题二分搜索中判断返回的条件为 当前版本为True且（当前索引为0 或 左边的版本为False）
- `m *` 的作用是避免 `m - 1` 为负数，如果 m 为 0，则代表左边没有版本，只需判断当前版本是否为 True
- True > False 或 0