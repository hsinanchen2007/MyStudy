```python
class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        # won't exceed 1000
        # integer is [0, 1000]
        # Time complexity : O(N**2*logN)
        # Space complexity : O(1)
        res = 0
        nums.sort()
        for i in range(len(nums)):
            if nums[i] == 0: continue
            for j in range(i + 1, len(nums)):
                if nums[j] == 0: continue
                a, b = nums[i], nums[j]
                index = bisect.bisect_right(nums, a + b - 1) - 1
                res += index - j
        return res
```