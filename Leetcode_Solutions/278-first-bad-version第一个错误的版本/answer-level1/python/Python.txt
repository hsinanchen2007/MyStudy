### 解题思路
此处撰写解题思路

### 代码

```python
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        l=0
        h=n
        while(l<h):
            m=l+(h-l)/2
            if isBadVersion(m):
                h=m
            else:
                l=m+1
        return l
```