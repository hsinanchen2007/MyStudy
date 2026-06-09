
```
class Solution:
    def maxArea(self, height: List[int]) -> int:
        if len(height) <=1: return -1
        i ,j ,res= 0, len(height) - 1, 0
        while i < j:
            res = max(res, min(height[i], height[j])*(j-i));
            if height[i] < height[j]: 
                i+=1
            else: 
                j-=1
        return res
```
