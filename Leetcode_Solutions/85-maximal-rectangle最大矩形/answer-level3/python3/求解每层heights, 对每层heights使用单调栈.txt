### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix: return 0
        if not matrix[0]: return 0
        def maxarea(heights):
            stack = [-1]
            N = len(heights)
            res = 0
            for i in range(N):
                while len(stack) > 1 and heights[i] <= heights[stack[-1]]:
                    res = max(res, heights[stack.pop()] * (i-1-stack[-1]))
                stack.append(i)
            for i in range(len(stack) - 1):
                res = max(res, heights[stack.pop()] * (N - 1 - stack[-1]))
            return res

        N = len(matrix)
        M = len(matrix[0])
        heights = [0] * M
        res = 0
        for i in range(N):
            if i == 0:
                heights = list(map(int, matrix[0]))
                res = max(res, maxarea(heights))
                continue
            for j in range(M):
                if matrix[i][j] == '0': heights[j] = 0
                if matrix[i][j] == '1': heights[j] += 1
            res = max(res, maxarea(heights))
        return res
```