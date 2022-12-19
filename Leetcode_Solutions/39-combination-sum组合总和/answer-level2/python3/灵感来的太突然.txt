不知道该说什么。。。


```
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()
        N = len(candidates)
        def addNum(ans: List[int], i: int, total: int):
            if i >= N: return
            while total+candidates[i] <= target:
                addNum(ans[:], i+1, total)
                total += candidates[i]
                ans.append(candidates[i])
            if total == target:
                res.append(ans)

        addNum([], 0, 0)
        return res
```
