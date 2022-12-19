跟上一个找子集的题目差不多，多一个剪枝
```
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return []
        ans = [[]]
        nums.sort()
        def helper(nums, tmp, ans):
            if not nums:
                return
            for index in range(len(nums)):
                if index > 0 and nums[index - 1] == nums[index]:
                    continue
                tmp.append(nums[index])
                ans.append(tmp[:])
                helper(nums[index + 1:], tmp, ans)
                tmp.pop()
        helper(nums, [], ans)
        return ans
```
