代码很简洁易懂～
```
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        left, right = 0, k-1
        res = []
        if not nums:
            return []
        if len(nums) <= k:
            return [max(nums)]
        while right <= len(nums) - 1:
            res.append(max(nums[left:right+1]))
            left += 1; right += 1
        return res
```
