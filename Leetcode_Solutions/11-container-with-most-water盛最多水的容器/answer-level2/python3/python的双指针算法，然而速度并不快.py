双指针算法
```
class Solution:
    def maxArea(self, height: List[int]) -> int:
        a = 1
        b = len(height)
        max_s = 0
        while a != b:
            max_s = max(max_s, (b - a) * min(height[a-1], height[b-1]))
            if height[a-1] > height[b-1]:
                b = b - 1
            else: 
                a = a + 1        
        return max_s
```
