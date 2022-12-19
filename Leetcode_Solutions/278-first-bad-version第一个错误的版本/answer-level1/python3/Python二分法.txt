### 解题思路
类似于二分查找法的思路

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
        mean = (1 + n)//2
        average = mean
        min_num = 0
        
        while 1:
            if not isBadVersion(average):
                min_num = average
                average = (average + 1 + n)//2
            if isBadVersion(average):
                if not isBadVersion(average - 1):
                    return average
                average = (min_num + average)//2
                
            
            
```