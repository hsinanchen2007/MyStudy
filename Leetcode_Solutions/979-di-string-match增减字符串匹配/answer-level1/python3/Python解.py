```
class Solution:
    def diStringMatch(self, S: str) -> List[int]:
        i=0
        j=len(S)
        res=[]
        for s in S:
            if s == "I":  #取最小
                res.append(i)
                i+=1
            if s == "D":  #取最大
                res.append(j)
                j-=1
        res.append(i)
        return res
```