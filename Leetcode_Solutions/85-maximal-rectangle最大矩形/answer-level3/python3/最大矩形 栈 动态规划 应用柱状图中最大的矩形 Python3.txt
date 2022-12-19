### 解题思路
执行用时 :80 ms, 在所有 Python3 提交中击败了97.38%的用户
内存消耗 :14.3 MB, 在所有 Python3 提交中击败了5.26%的用户

### 代码

```python3
class Solution:
    
    def largestRectangleArea(self, heights):
        heights = [0] + heights + [0]  # 哨兵
        max_squ = 0
        stk = []
        # 每个元素都入栈
        for i in range(len(heights)):
            # 什么时候出栈
            while len(stk) > 0 and heights[i] < heights[stk[-1]]:
                h = heights[stk.pop()]
                if heights[stk[-1]] == h:
                    stk.pop()
                w = i - stk[-1] - 1
                squ = w * h

                if squ > max_squ:
                    max_squ = squ
            stk.append(i)
        return max_squ

    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        
        max_area = 0
        
        dp = [0] * len(matrix[0])
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                # 从上向下累加
                dp[j] = dp[j] + 1 if matrix[i][j] == '1' else 0
            
            max_area = max(max_area, self.largestRectangleArea(dp))
        
        return max_area

            
```