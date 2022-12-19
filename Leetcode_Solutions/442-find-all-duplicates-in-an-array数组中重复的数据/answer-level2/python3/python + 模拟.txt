```python
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        res = []
        for i, num in enumerate(nums):
            if i + 1 == num: continue
            while True:
                t = nums[i]
                if nums[t - 1] == t:break
                nums[i], nums[t - 1] = nums[t - 1], t
        return [num for i, num in enumerate(nums) if i + 1 != num]
```