```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        for i, num in enumerate(nums):
            if i + 1 != num:
                while True:
                    t = nums[i]
                    if t <= 0 or t > len(nums) or nums[t - 1] == t: break
                    nums[i], nums[t - 1] = nums[t - 1], nums[i]
        for i, num in enumerate(nums): 
            if i + 1 != num: return i + 1 
        return len(nums) + 1
```