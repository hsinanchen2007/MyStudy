```
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        if len(nums) < 3:
            return []
        result = []
        nums.sort()
        min_diff = 2**33
        for i in range(len(nums)-1, 1, -1):
            j, k = 0, i-1
            while j < k:
                m = nums[j] + nums[k] + nums[i]
                diff = target - m
                if diff == 0:
                    return target
                if min_diff > abs(diff):
                    min_diff = abs(diff)
                    result.append(m)
                    if diff > 0:
                        j += 1
                    else:
                        k -= 1
                elif diff > 0:
                    j += 1
                else:
                    k -= 1
        return result[-1]
```
