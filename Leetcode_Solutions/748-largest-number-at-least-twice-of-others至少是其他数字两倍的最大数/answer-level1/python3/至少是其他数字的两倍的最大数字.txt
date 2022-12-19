### 解题思路
最直白的解法

### 代码

```python
class Solution(object):
    def dominantIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        new_nums = sorted(nums)
        if len(nums) == 1:
            return 0
        elif new_nums[-1] >= new_nums[-2]*2:
            for i in range(len(nums)):
                if nums[i] == new_nums[-1]:
                    return i 
        else:
            return -1
```