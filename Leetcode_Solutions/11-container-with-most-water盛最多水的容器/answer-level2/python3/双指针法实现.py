### 解题思路
此处撰写解题思路

### 代码

```python3

class Solution:
    def maxArea(self, height: List[int]) -> int:
        """双指针法"""
        i, j = 0, len(height) - 1
        maxA = 0
        while i < j:
            left_h = height[i]
            right_h = height[j]
            maxA = max(maxA, (j - i) * min(left_h, right_h))
            if height[i] <= height[j]:
                i += 1
                while height[i] <= left_h and i < j:
                    i += 1
            else:
                j -= 1
                while height[j] <= right_h and i < j:
                    j -= 1
        return maxA

```