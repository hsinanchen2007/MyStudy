```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        N = len(nums)
        for i in range(N):
            if nums[i] <= 0:
                nums[i] = N + 1
        ni = 0
        for i in range(N):
            ni = abs(nums[i]) - 1
            if ni < N:
                nums[ni] = -abs(nums[ni])
        for i in range(N):
            if nums[i] > 0:
                return i + 1
        return N + 1
```