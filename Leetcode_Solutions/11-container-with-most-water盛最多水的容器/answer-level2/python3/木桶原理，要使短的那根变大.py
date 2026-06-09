初始取两端的值，然后移动短的那根
```
class Solution:
    def maxArea(self, height: List[int]) -> int:
        max=0
        p=0
        q=len(height)-1
        while p<q:
            if height[p]<height[q]:
                t=height[p]*(q-p)
                p+=1
            else:
                t = height[q] * (q - p)
                q-=1
            if t>max:
                max=t
        return max
```
