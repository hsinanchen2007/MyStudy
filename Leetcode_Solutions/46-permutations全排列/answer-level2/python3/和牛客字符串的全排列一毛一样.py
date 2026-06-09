```
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        def dfs(arr, path):
            if not arr:
                res.append(path)
            for i in range(len(arr)):
                if i > 0 and arr[i] == arr[i - 1]:
                    continue
                dfs(arr[:i] + arr[i+1:], path + [arr[i]])
        dfs(nums, [])
        return res
```