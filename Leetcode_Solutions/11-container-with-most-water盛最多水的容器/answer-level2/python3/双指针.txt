```
class Solution:
    def maxArea(self, height: List[int]) -> int:
        l=0
        r=len(height)-1
        re=0
        while l<r:
            w=r-l
            h=min(height[l],height[r])
            tmpre=w*h
            re=max(tmpre,re)
            if h==height[l]: #表示是height[l],限制了发展空间，所以要找更高的l
                l+=1
            else:
                r-=1
        return re
            
```
