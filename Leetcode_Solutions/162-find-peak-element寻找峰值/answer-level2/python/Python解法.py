### 解题思路
暴力解法即每个数字依次遍历，但是这样会导致时间复杂度为O(n)
为了降低时间复杂度，考虑二分的方式。取出中间的值middle，以及其对应左右两边的值left和right。如果middle最大，则返回middle的索引。
还剩下递增和递减两种情况。考虑递增情况，如果是递增的话，右半边会出现两种情况，一种是一直增长下去，另一种是突然降低。对于第一种情况，由于nums[n]为负无穷，所以肯定存在峰值。对于第二种情况，也肯定存在峰值，所以当递增的时候，在右半边找峰值就好了，同理，递减在左半边找峰值。

### 代码

```python
class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1:
            return 0
        if len(nums) == 2:
            if nums[0]>nums[1]:
                return 0
            else:
                return 1
        value = nums[len(nums)//2]
        left = nums[len(nums)//2 - 1]
        right = nums[len(nums)//2 + 1]
        if value > left and value > right:
            return len(nums)//2
        elif left < right:
            return len(nums)//2 + 1 + self.findPeakElement(nums[len(nums)//2+1:])
        else:
            return self.findPeakElement(nums[:len(nums)//2])
```