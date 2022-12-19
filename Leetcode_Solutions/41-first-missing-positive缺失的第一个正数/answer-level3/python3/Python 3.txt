```python3 []
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums.sort()
        i = 1
        j = 0
        while j < len(nums) and nums[j] <= 0:
            j += 1
        while j < len(nums):
            if nums[j] == i:
                i += 1
                while j+1 < len(nums) and nums[j] == nums[j+1]:
                    j += 1
            else:
                break
            j += 1
        return i
```