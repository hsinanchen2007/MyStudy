```python
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        def dfs(index, target, tempK, tempArr):
            if tempK == k:
                if target == 0:
                    res.append(tempArr[:])
            for i in range(index, 10):
                if i > target: break
                tempArr.append(i)
                dfs(i + 1, target - i, tempK + 1, tempArr)
                tempArr.pop()
        dfs(1, n, 0, [])
        return res
```