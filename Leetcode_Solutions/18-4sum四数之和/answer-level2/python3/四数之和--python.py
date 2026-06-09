```
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        if len(nums) < 4:
            return []
        result = []
        nums.sort()
        for i in range(len(nums)-1, 1, -1):
            for j in range(i-1, 1, -1):
                if j < i-1 and nums[j] == nums[j+1]:
                    continue
                m = target - nums[i] - nums[j]
                k, l = 0, j-1
                while k < l:
                    if nums[k] + nums[l] == m:
                        if [nums[k], nums[l], nums[j], nums[i]] not in result:
                            result.append([nums[k], nums[l], nums[j], nums[i]])
                        k += 1
                        l -= 1
                        while k < i-1 and nums[k] == nums[k-1]:
                            k += 1
                        while l >= 0 and nums[l] == nums[l+1]:
                            l -= 1
                    elif nums[k] + nums[l] < m:
                        k += 1
                    else:
                        l -= 1
        return result
```
