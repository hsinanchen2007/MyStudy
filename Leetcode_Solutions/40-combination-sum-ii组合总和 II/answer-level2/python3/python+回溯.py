把上一题稍微改了一下
```
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        if (not candidates):
            return []
        n = len(candidates)
        res = []
        candidates.sort()
        def helper(i, tmp, target):
            if (target == 0) and tmp not in res:
                res.append(tmp)
                return
            if (i == n or target < candidates[i]):
                return
            helper(i+1, tmp + [candidates[i]], target - candidates[i])
            helper(i+1, tmp, target)
        helper(0, [], target)
        return res

```
