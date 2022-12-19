```
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        length=len(candidates)
        res=[]
        def tb(i,t,s):
            if i>length or t>target:
                return
            elif t==target:
                res.append(s)
                return
            for j in range(i,length):
                if j>i and candidates[j]==candidates[j-1]:
                    continue
                if t+candidates[j]>target:
                    return
                tb(j+1,t+candidates[j],s+[candidates[j]])
        tb(0,0,[])
        return res
```
