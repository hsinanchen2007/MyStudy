### 解题思路
时间复杂度O(nlogn)
空间复杂度O(n)

### 代码

```python
class Solution(object):
    def smallerNumbersThanCurrent(self, nums):
        nums_copy = sorted(nums)
        for i,c in enumerate(nums):
            nums[i] = nums_copy.index(c)
        return nums
```