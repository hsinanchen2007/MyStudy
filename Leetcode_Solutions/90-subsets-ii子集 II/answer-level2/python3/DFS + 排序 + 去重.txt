又是一道DFS去重问题，对于这类问题我们只要记住每次记录元素的id就行，判断重复数据id是否已经在tmp中
```py3
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return []
        ans = []
        nums.sort()
        def dfs(tmp, idx):
            ans.append([nums[i] for i in tmp])
            for i in range(idx, len(nums)):
                if i > 0 and nums[i] == nums[i - 1] and i - 1 not in tmp:
                    continue
                tmp.append(i)
                dfs(tmp, i + 1)
                tmp.pop()
        dfs([], 0)
        return ans 

```