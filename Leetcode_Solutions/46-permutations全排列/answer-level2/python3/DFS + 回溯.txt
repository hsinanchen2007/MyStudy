DFS + 回溯模板题，注意剪枝
```py3
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        def dfs(index, idx):
            if len(index) == len(nums):
                ans.append([nums[i] for i in index])
                return
            for i in range(len(nums)):
                if i not in index:
                    index.append(i)
                    dfs(index, i)
                    index.pop()
        dfs([], 0)
        return ans
```