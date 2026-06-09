```python
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        # two pointer
        # Time complexity  : O(N)
        # Space complexity : O(1)
        if k == 0: return 0
        l, r = 0, 0
        tmp, res = 1, 0
        while r < len(nums):
            tmp *= nums[r]
            while tmp >= k and l < len(nums):
                tmp /= nums[l]
                l += 1
            if r >= l: res += (r - l + 1)
            r += 1
        return res
```