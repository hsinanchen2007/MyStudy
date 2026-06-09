### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        totalSum = sum(nums)
        leftSum = 0
        for i in range(len(nums)):
            if leftSum * 2 + nums[i] == totalSum:
                return i
            else:
                leftSum += nums[i];
        return -1

```