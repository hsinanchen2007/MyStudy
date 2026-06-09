双指针，每个位置能接水和它左边、右边最大的高度的最小值有关。
```
class Solution:       
    def trap(self, height: List[int]) -> int:
        if len(height) == 0: return 0
        left = 0
        right = len(height) - 1
        res = 0
        left_max = height[left]
        right_max = height[right]
        while left < right:
            # 移动方向
            if left_max <= right_max:
                if height[left] < left_max:
                    res += left_max - height[left]
                left += 1
                left_max = max(left_max, height[left])
            else:
                if height[right] < right_max:
                    res += right_max - height[right]
                right -= 1
                right_max = max(right_max,height[right])
        return res
```
