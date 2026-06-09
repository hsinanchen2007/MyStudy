
第一步剪枝 应该都是很清楚 。candidates[i] > target的时候 肯定是不能成立的
第二步剪枝，比如在 candidates = [2, 3,6,7]、target = 7的时候 2 2 3 就行了 2 3 2 ，3 2 2的时候 其实就一个升序2 2 3就好了。
所以需要进行第二步判断就容易理解了
```

class Solution:
    def __init__(self):
        self.res = []
        self.path = []

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        if len(candidates) == 0:
            return []
        candidates.sort()
        self.dfs(candidates, target)
        return self.res

    def dfs(self, candidates: List[int], target: int):
        lng = len(candidates)
        if target == 0:
            self.res.append(self.path.copy())
            return
        for i in range(lng):
            # 直接就是剪枝了 但是这只是其中一步的剪枝
            if candidates[i] > target:
                break
			# 下面是第二步的剪枝
            if len(self.path) > 0 and candidates[i] < self.path[-1]:
                continue
            self.path.append(candidates[i])
            tmp = target - candidates[i]
            self.dfs(candidates, tmp)
            self.path.pop()
```
