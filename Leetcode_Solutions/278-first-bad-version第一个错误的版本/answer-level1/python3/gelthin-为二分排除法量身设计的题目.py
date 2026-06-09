### 解题思路
这一题是为二分排除法量身设计的，因为只能判断 mid < target, 还是 mid >= target, 无法直接判断 mid == target
因此只需要判断一下。
当然最后还需要最好确认一下。

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
        if (n<=1):
            return n

        left, right = 1, n
        while (left<right):
            mid = (left+right)//2
            if isBadVersion(mid) == False:
                left = mid+1
            else:
                right = mid
        return left

```