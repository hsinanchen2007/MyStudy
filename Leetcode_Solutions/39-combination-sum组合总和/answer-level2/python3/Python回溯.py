start用来避免重复输出，比如[2,2,3],[2,3,2],[3,2,2]这三种其实只表示一个组合，我们只挑选递增排列的。设置start，每次递归的时候只在candidates中当前及之后的数字中选择。
```python
class Solution:
    def combinationSum(self, candidates: List[int],
                       target: int) -> List[List[int]]:
        self.res = []
        self.backtrack(candidates, [], target, 0)
        return self.res

    def backtrack(self, candidates, track, target, start):
        if sum(track) == target:
            self.res.append(track)
            return
        if sum(track) > target:
            return
        for i in range(start, len(candidates)):
            self.backtrack(candidates, track + [candidates[i]], target, i)
```