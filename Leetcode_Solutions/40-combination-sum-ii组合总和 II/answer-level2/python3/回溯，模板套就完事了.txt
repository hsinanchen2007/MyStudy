### 解题思路
labuladong的模板，套就完事了

### 代码

```python3
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        result = []
        def backtrack(start, tmp,track):
            if tmp == target:
                if track not in result:
                    result.append(track[:])
                return
            if tmp>target:
                return
            
            for i in range(start, len(candidates)):
                if tmp+candidates[i]>target:
                    break
                track.append(candidates[i])
                backtrack(i+1, tmp+candidates[i], track)
                track.pop()
        backtrack(0, 0, [])
        return result
```