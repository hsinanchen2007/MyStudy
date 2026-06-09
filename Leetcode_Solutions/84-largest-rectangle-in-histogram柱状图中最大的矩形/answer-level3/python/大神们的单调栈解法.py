### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = [-1]
        N = len(heights)
        res = 0
        for i in range(N):
            while len(stack) > 1 and heights[i] <= heights[stack[-1]]:
                res = max(res, heights[stack.pop()] * (i - 1 - stack[-1]))
            stack.append(i)
        for i in range(len(stack) - 1):
            res = max(res, heights[stack.pop()] * (len(heights) - 1 - stack[-1]))
        return res
```