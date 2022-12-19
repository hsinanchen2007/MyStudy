```
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        if len(nums) < 4:
            return []
        nums = sorted(nums)
        length = len(nums)
        res = []
        for i in range(length):
            for j in range(i + 1, length):
                L = j + 1
                R = length - 1
                while L < R:
                    f_sum = nums[i] + nums[j] + nums[L] + nums[R]
                    if f_sum < target:
                        L += 1
                    elif f_sum > target:
                        R -= 1
                    else:
                        if [nums[i], nums[j], nums[L], nums[R]] not in res:
                            res.append([nums[i], nums[j], nums[L], nums[R]])
                        L += 1
                        R -= 1
        return res

```
