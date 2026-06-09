```
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        length=len(candidates)
        res=[]
        def tb(i,t,s):
            if t>target or i==length:
                return
            elif t==target:
                res.append(s)
            for j in range(i,length):
                if t+candidates[j]>target:
                    return
                tb(j,t+candidates[j],s+[candidates[j]])
        tb(0,0,[])
        return res
```
