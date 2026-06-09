```
class Solution:
    def maxArea(self, height: List[int]) -> int:
        i,j = 0,len(height)-1
        maxh = 0
        if len(height) == 0:
            return 0
        while i<j:
            if height[i] < height[j]:
                maxh = max(maxh,(j-i)*height[i])
                i += 1
            if height[i] >= height[j]:
                maxh = max(maxh,(j-i)*height[j])
                j -= 1
        return maxh
```