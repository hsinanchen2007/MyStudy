```
class Solution:
    def pairSums(self, nums: List[int], target: int) -> List[List[int]]:
        start, end = 0, len(nums) - 1
        res = []
        nums = sorted(nums)
        while start < end:
            if nums[start] + nums[end] > target:
                end -= 1
            elif nums[start] + nums[end] < target:
                start += 1
            else:
                res.append([nums[start], nums[end]])
                start += 1
                end -= 1
        return res
```
