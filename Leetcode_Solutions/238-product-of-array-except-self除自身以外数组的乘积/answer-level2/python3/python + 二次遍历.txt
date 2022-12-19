```python
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        tempArr = [1] * len(nums)
        cnt = 1
        for i in range(len(nums)):
            tempArr[i] *= cnt
            cnt = nums[i] * cnt
        cnt = 1
        for i in range(len(nums) - 1, -1, -1):
            tempArr[i] *= cnt
            cnt = nums[i] * cnt
        return tempArr
```