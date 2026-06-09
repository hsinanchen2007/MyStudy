```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        if nums == []: return 0
        if len(nums) <= 2: return max(nums)
        pre_two, pre_one = nums[0], max(nums[0], nums[1])
        for i in range(2, len(nums)):
            pre_one, pre_two = max(pre_one,  pre_two + nums[i]), pre_one
        return pre_one
```