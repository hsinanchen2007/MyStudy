剪枝好像不对😂
```
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        if not n or not k:
            return []
        ans = []
        nums = [x for x in range(1,n+1)]
        def helper(nums,tmp,ans):
            if len(tmp) == k:
                ans.append(tmp[:])
                return
            for index in range(len(nums)):
                if nums[index] == nums[-1] and len(tmp)+1 != k:
                    continue
                tmp.append(nums[index])
                helper(nums[index+1:],tmp, ans)
                tmp.pop()
        helper(nums, [], ans)
        return ans
```
