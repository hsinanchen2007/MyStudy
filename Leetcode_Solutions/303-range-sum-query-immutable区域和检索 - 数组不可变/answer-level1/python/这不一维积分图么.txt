做图像处理的人都知道积分图，这不就是一维的么
```
class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.cacheLine = [sum(nums[:i+1]) for i in range(len(nums))]

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.cacheLine[j] - self.cacheLine[i-1] if i != 0 else self.cacheLine[j]
```
