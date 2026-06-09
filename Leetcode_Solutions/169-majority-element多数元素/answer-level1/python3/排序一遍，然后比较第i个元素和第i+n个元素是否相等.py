### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = sorted(nums)
        n = int(len(nums)/2)
        if len(nums) <= 1:
            return nums[0]
        for i in range(0,len(nums)):
            if nums[i] == nums[i+n]:
                return nums[i]
```