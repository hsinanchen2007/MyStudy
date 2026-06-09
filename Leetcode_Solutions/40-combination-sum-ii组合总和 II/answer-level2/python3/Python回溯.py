```python
class Solution:
    def combinationSum2(self, candidates: List[int],
                        target: int) -> List[List[int]]:
        self.res = []
        candidates.sort()
        self.backtrack(candidates, [], 0, target)
        return self.res

    def backtrack(self, candidates, track, start, target):
        if sum(track) == target:
            self.res.append(track)
            return
        if sum(track) > target:
            return
        for i in range(start, len(candidates)):
            if i > start and candidates[i] == candidates[i-1]:
                continue
            self.backtrack(candidates, track + [candidates[i]], i + 1, target)
```