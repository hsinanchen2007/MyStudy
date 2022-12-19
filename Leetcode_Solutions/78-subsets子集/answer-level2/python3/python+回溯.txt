感觉有点慢
```
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return []
        ans = [[]]
        nums.sort()
        def helper(nums, tmp, ans):
            if not nums:
                return
            for index in range(len(nums)):
                tmp.append(nums[index])
                ans.append(tmp[:])
                helper(nums[index + 1:], tmp, ans)
                tmp.pop()
        helper(nums, [], ans)
        return ans
```
