```
class Solution:
    def largeGroupPositions(self, S: str) -> List[List[int]]:
        n=len(S)
        l,r,res=0,1,[]
        if n<3:
            return []
        while r<n:
            if S[l]!=S[r]:
                if r-l>=3:
                    res.append([l,r-1])
                l,r=r,r+1
            elif r==n-1 and l<=n-3:
                res.append([l,r])
                break
            else:
                r+=1
        return res
```
