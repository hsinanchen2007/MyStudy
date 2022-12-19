```
class Solution:
    def minArea(self, image: List[List[str]], x: int, y: int) -> int:
        l=r=u=d=-1
        for i in range(len(image)):
            for j in range(len(image[0])):
                if image[i][j]=='1':
                    l=j if l==-1 else min(l,j)
                    r=j if r==-1 else max(r,j)
                    u=i if u==-1 else min(u,i)
                    d=i if d==-1 else max(d,i)
        return (d-u+1)*(r-l+1)
```
