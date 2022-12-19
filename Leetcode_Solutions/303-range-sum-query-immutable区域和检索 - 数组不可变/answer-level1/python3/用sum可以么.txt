```python
class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.nums=nums
        

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return sum(self.nums[i:j+1])

```
小白一个，这样岂不是更简单，系统也AC了，只不过只超过了25%而已。为何大家第一时间考虑到的是动态规划呢？遇到这种题大家首先是怎么思考的呢？