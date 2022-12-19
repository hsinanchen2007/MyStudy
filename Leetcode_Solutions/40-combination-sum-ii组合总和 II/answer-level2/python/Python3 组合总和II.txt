### 解题思路
![7.png](https://pic.leetcode-cn.com/90b07980294559c76f69f5a079b2c5cf171ff1f9891bfeec74009ec022b915e3-7.png)


### 代码

```python3
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        self.res = []
        if len(candidates) == 0:
            return []
        candidates.sort()
        self.DFS([], candidates, target, 0)
        return self.res

    def DFS(self, track, candidates, target, start):
        if target == 0:
            self.res.append(track.copy())
            return
        for i in range(start, len(candidates)):
            if candidates[i] <= target:
                if i != start and candidates[i] == candidates[i - 1]:
                    continue
                track.append(candidates[i])
                self.DFS(track, candidates, target - candidates[i], i + 1)
                track.pop()
            else:
                break
                
```