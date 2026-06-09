
```
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        maxh=heights[0]
        minh=heights[0] 
        hh=[]
        count=0
        for i in range(1,len(heights)):
            if maxh<heights[i]:
                maxh=heights[i]
            if minh>heights[i]:
                minh=heights[i]
        h=[0]*(maxh-minh+1)
        for i in range(0,len(heights)):
            h[heights[i]-minh]+=1
        for i in range(0,len(h)):
                hh+=[i+minh]*h[i]
        #print(hh)
        for i in range(0,len(heights)):
            if hh[i]!=heights[i]:
                count+=1
        return count