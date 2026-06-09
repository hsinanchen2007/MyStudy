```
class Solution:
    def trap(self, height: List[int]) -> int:
        left_max = {}
        right_max = {}
        left_max[0] = 0
        ans = 0
        for i in range(1,len(height)):
            left_max[i] = max(height[i-1],left_max[i-1])
        right_max[len(height)-1] = 0
        for i in range(len(height)-2,-1,-1):
            right_max[i] = max(height[i+1],right_max[i+1])
        for i in range(1,len(height)):
            if min(right_max[i],left_max[i])-height[i]>0:
                ans += min(right_max[i],left_max[i])-height[i]
            else:
                pass
        return ans
```
