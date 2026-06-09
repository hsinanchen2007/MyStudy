### 解题思路
二分法的边界设置为right-left>1。
这样需要在二分之前。即left==1时，判断如果isBadVersion(left)==True，说明第一个版本有错误，返回1。
如果只有两个版本，第二个版本有错误，返回2。
然后进入二分法，判断哪个位置有错误。
判断结束时，应该是right记录第一个错误的版本号

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
        left = 1
        right = n
        if isBadVersion(left):
            return 1
        elif isBadVersion(right) and right-left==1:
            return 2
        while right-left>1:
            l = isBadVersion(left)
            r = isBadVersion(right)
            mid = isBadVersion((left+right)//2)
            if mid==False:
                left = (left+right)//2
            elif mid==True:
                right = (left+right)//2
        return right
                
```