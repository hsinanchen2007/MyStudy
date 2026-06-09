```
class Solution:
    def maxArea(self, height: List[int]) -> int:
        # 官方解题思路中的双指针思路
        b = 0
        e = len(height) - 1
        contain = 0
        while b < e:
            contain = max(contain, (e-b)*min(height[b],height[e]))
            if height[b] > height[e]:
                e -= 1
            else:
                b += 1
        
        return contain
```