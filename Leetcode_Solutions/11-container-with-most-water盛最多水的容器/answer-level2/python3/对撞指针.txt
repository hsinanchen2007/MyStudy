对于像求数组中两数最大和、等于目标数、回文字符串等这样类型的问题，都可以用对撞指针来解决
```
class Solution:
    def maxArea(self, height: List[int]) -> int:
        i, j, s = 0, len(height) - 1, 0
        while i < j:
            if height[i] > height[j]:
                if (j - i) * height[j] > s:
                    s = (j - i) * height[j]
                j -= 1
            else:
                if (j - i) * height[i] > s:
                    s = (j - i) * height[i]
                i += 1
        return s
```
