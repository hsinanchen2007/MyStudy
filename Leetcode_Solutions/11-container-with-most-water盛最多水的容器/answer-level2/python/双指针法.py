### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:
        if len(height) <= 1:
            return 0
        left, right, res = 0, len(height)-1, 0
        while left<right:
            if height[left] < height[right]:
                res = max(res, height[left] * (right - left))
                left += 1
            else:
                res = max(res, height[right] * (right - left))
                right -= 1
        return res



```