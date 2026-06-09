``` python
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums = sorted(nums)
        result = set()
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                # findTwoNumberTarget(nums[j+1:], target-nums[i]-nums[j])
                t = target - nums[i] - nums[j]
                l, r = j+1, len(nums)-1
                while l < r:
                    if nums[l] + nums[r] < t:
                        l += 1
                    elif nums[l] + nums[r] > t:
                        r -= 1
                    else:
                        result.add((nums[i], nums[j], nums[l], nums[r]))
                        l += 1
                        r -= 1
        return list(result)
```