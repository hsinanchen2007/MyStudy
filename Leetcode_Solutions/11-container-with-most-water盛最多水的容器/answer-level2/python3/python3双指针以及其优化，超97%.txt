### 解题思路
超过97%,双指针以及其优化，避免不必要的比较，每次移动直接移到比当前元素大的元素位置处

### 代码

```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        if n == 0:
            return 0
        max_ = 0
        left = 0
        right = n-1
        while left < right:
            max_ = max(max_,(right-left)*min(height[right],height[left]))
            if height[left] < height[right]:
                temp = height[left]
                left += 1
                while left>right and height[left] <= temp:
                    left += 1
            else:
                temp = height[right]
                right -= 1
                while left<right and  temp >= height[right]:
                    right -= 1
        return max_
```