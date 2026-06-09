### 解题思路
- 当isBadVersion(mid) 为 False 且 isBadVersion(mid+1）为True同时满足时返回mid+1,否则继续二分查找

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
        left,right = 0,n      
        while left < right:
            mid = (left + right) // 2
            if not isBadVersion(mid) and isBadVersion(mid+1):
                break
            if isBadVersion(mid):
                right = mid
            else:
                left = mid       
        return mid+1
            
```