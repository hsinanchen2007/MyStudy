```
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return []
        ans = []
        nums.sort()
        def helper(nums,n,tmp, ans):
            if len(tmp) == n:
                ans.append(tmp[:])
                return
            for index in range(len(nums)):
                if index > 0 and nums[index - 1] == nums[index]:
                    continue
                tmp.append(nums[index])
                helper(nums[:index]+nums[index+1:], n,tmp, ans)
                tmp.pop()
        helper(nums,len(nums),[],ans)
        return ans
```
