```
class Solution:
    def largeGroupPositions(self, S: str) -> List[List[int]]:
        length = 0
        s = S[0]
        r = []
        start=0
        end=0
        for i in range(len(S)):
            if S[i]==s:
                length+=1
                end=i
            else:
                if length>=3:
                    r.append([start, end])
                start,end=i,i
                s=S[i]
                length=1
        if length>=3:
            r.append([start, end])
        return r
```
