```
class Solution:
    def trap(self, height: List[int]) -> int:
        all_rain = 0
        for i in range(1,len(height)-1):
            all_rain+=max((min(max(height[0:i]),max(height[i:]))-height[i]),0)
        return all_rain
```
