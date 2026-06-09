### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if len(matrix) == 0:
            return 0
        maxArea = 0
        heigh = [0 for i in range(len(matrix[0]))]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == "1":
                    heigh[j] += 1
                else:
                    heigh[j] = 0
            maxArea = max(maxArea, self.largestRectangleArea(heigh))
        return maxArea
    def largestRectangleArea(self, heights: List[int]) -> int:
        if heights is None or len(heights) == 0:
            return 0
        # 单调栈 min
        stack = []
        maxArea = 0
        n = len(heights)
        for i in range(n):
            while stack and heights[stack[-1]] >= heights[i]:
                j = stack.pop()
                k = stack[-1] if stack else -1
                curArea = (i - k - 1) * heights[j]
                maxArea = max(maxArea, curArea)
            stack.append(i)
        while stack:
            j = stack.pop()
            k = stack[-1] if stack else -1
            curArea = (n - k - 1) * heights[j]
            maxArea = max(maxArea, curArea)
        return maxArea
                
```