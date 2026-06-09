```
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return []
        if len(nums)==1:
            return [nums]
        nums.sort()
        res = []
        for i in range(len(nums)):
            if i > 0 and nums[i]==nums[i-1]:
                continue
            for j in self.permuteUnique(nums[:i]+nums[i+1:]):
                res.append([nums[i]]+j)
        return res
```