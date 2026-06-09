### 解题思路
此处撰写解题思路

### 代码

```python3

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        """
        采用栈的方式，速度最快
        """
        size = len(heights)
        res = 0
        # 前后补0，保证进栈与出栈
        heights = [0] + heights + [0]
        stack = []
        size += 2

        for i in range(size):
            #
            while len(stack) > 0 and heights[i] < heights[stack[-1]]:
                cur_height = heights[stack.pop()]

                while len(stack) > 0 and cur_height == heights[stack[-1]]:
                    stack.pop()

                cur_width = i - stack[-1] - 1
                res = max(res, cur_height * cur_width)
            stack.append(i)
        # print(stack) # [0, 1, 20001]
        return res

    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        # 先转成成数字
        if not matrix or not matrix[0]: return 0
        matrix = [[int(j) for j in i] for i in matrix]

        m = len(matrix)
        n = len(matrix[0])

        # 处理数据
        for i in range(n):
            for j in range(1, m):
                # 根据上行的值决定现在的值
                if matrix[j][i] == 1:
                    matrix[j][i] = matrix[j - 1][i] + 1

        res = 0
        for i in range(m):
            res = max(res, self.largestRectangleArea(matrix[i]))

        return res
```