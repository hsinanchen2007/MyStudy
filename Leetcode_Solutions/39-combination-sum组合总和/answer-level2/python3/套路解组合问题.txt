 **两种解法，异曲同工之妙**
1. 解法一：
```python
from typing import List
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def backtrack(p: List[int], target: int, start: int):
            for i in range(start, L):
                a = candidates[i]
                if target > candidates[i]:
                    backtrack(p + [a], target - a, i)
                elif target == candidates[i]:
                    output.append(p + [a])

        L = len(candidates)
        output = []
        backtrack([], target, 0)
        return output
```
2. 解法二：
```python
from typing import List
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def backtrack(target,start):
            if target == 0:
                output.append(p.copy())
                return
            for i in range(start,len(candidates)):
                if target >= candidates[i]:
                    p.append(candidates[i])
                    backtrack(target - candidates[i],i)
                    p.pop()

        # candidates.sort()
        output = []
        p = []
        backtrack(target,0)
        return output
```



