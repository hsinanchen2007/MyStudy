### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:
        ma = 0
        mi = 0
        for i in range(len(height)):
            if height[i] <= mi:
                continue
            mi = height[i]

            for j in range(len(height) - 1, i, -1):
                area = min(height[i], height[j]) * (j - i)
                if area > ma:
                    ma = area
                if height[j] >= mi:                    
                    break
        return ma
```