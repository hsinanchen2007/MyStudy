### 解题思路
 target-candidates[i]<0就剪枝，path加入res 去重

### 代码

```python3
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        if not candidates:
            return []
        candidates.sort()

        res = []

        def dfs(candidates: List[int], begin: int, end: int, target: int, path: List[int], res: List[List[int]]):
            if target == 0:
                if path not in res:
                    res.append(path)

            for i in range(begin, end):
                dif = target - candidates[i]
                if dif < 0:
                    break

                dfs(candidates, i + 1, end, dif, path + [candidates[i]], res)

        dfs(candidates, 0, len(candidates), target, [], res)
        return res
```