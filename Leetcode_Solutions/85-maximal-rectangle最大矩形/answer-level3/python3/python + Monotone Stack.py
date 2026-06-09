```python
class Solution:
    def maximalRectangle(self, matrix: List[List[int]]) -> int:
        # Time complexity : O(MN)
        # Space complexity : O(N)
        if matrix == []: return 0
        row, col = len(matrix), len(matrix[0]) 
        heights = [0] * len(matrix[0])
        max_area = 0
        # 1 2 5 1 5 float('-inf') => max_area
        # stack -1 2, 1, 5, 5, 1
        
        def getRowArea(heights):
            stack = [-1]
            heights.append(float('-inf'))
            tmp_area = 0
            for i, height in enumerate(heights):
                while stack and heights[stack[-1]] > height:
                    index = stack.pop()
                    pre_height = heights[index]
                    tmp_area = max(tmp_area, (i - stack[-1] - 1) * pre_height)
                stack.append(i)
            heights.pop()
            return tmp_area
        for i in range(row):
            for j in range(col):
                if matrix[i][j] == '1': heights[j] += 1
                else: heights[j] = 0
            max_area = max(max_area, getRowArea(heights))
        return max_area
```