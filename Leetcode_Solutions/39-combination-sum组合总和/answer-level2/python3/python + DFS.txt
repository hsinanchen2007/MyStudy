```python
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        def dfs(index, tempSum, tempArr):
            if tempSum > target: return
            if tempSum == target:
                res.append(tempArr[:])
                return
            for i in range(index, len(candidates)):
                tempArr.append(candidates[i])
                dfs(i, tempSum + candidates[i], tempArr)
                tempArr.pop()
        dfs(0, 0, [])
        return res

```