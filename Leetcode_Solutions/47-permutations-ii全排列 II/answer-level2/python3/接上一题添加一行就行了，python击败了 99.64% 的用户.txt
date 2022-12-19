```
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        def back_track(nums, temp_l):
            if not nums:
                res.append(temp_l)
                return
            for i in range(len(nums)):
                if i > 0 and nums[i] == nums[i-1]: continue  # 此处为添加
                back_track(nums[:i]+nums[i+1:], temp_l+[nums[i]])
        nums.sort()
        back_track(nums, [])
        return res
```
