```
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums:
            return nums
        i = 0
        j = k-1
        res = []
        while j <= len(nums) - 1:
            cur_max = max(nums[i:j+1])
            i += 1
            j += 1
            res.append(cur_max)
        return res
        



```
