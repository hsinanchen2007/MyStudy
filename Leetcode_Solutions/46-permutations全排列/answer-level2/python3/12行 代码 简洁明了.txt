比较简洁的代码，看着舒服一些
```
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        path = []
        def dfs(nums, path, res):
            # 条件
            if len(path) == len(nums):
                res.append(path[:])
                return
            # 深度优先递归
            for i in range(len(nums)):
                if nums[i] not in path:
                    path.append(nums[i])
                    dfs(nums, path, res)
                    path.pop()

        dfs(nums, path, res)   

        return res
```
