```python
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res = []
        def dfs(index, target, tempArr):
            if target == 0: 
                res.append(tempArr[:])
                return
            for i in range(index, len(candidates)):
                if i > index and candidates[i] == candidates[i - 1]: continue
                if candidates[i] > target: break
                tempArr.append(candidates[i])
                dfs(i + 1, target - candidates[i], tempArr)
                tempArr.pop()
        dfs(0, target, [])
        return res
```