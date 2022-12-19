### 解题思路
此处撰写解题思路 我这个应该好理解吧~

### 代码

```python3
import copy
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        result = []
        cand = []

        def helper(cand,rest,tmp):
            if rest < 0:
                return 
            if rest == 0:
                result.append(copy.deepcopy(tmp))
                return 
            for i in range(len(cand)):
                if cand[i] == cand[i-1] and i > 0:
                        continue
                tmp.append(cand[i])
                helper(cand[i+1:],rest-cand[i],tmp)
                tmp.pop()
        
        helper(candidates,target,[])
        return result
```