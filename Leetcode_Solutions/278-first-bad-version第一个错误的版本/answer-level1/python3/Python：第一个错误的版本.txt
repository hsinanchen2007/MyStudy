### 解题思路
用Python刷题，第一次完完整整老老实实写二分算法，必须写这个题解，记录一下

### 代码

```python3
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
        l,r=0,n
        while l<r:
            m=(l+r)//2
            if isBadVersion(m):
                r=m
            else:
                l=m+1
        return l
```