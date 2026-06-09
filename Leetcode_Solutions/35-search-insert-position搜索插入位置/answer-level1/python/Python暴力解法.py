### 解题思路
由于是有序数组，倘若比最后一个还大就可以插入到最后一个位置了，如果不是就可以插入到前面。

### 代码

```python
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if target in nums:
            return nums.index(target)
        else:
            for i in range(0, len(nums)):
                if nums[-1] < target:
                    return len(nums)
                elif nums[i] > target:
                    return i
```