### 解题思路
用直方图的方法做的，用内部函数不断更新res值

### 代码

```
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        ans = 0
        def _maxRectangle(heights):
            heights = [0]+heights+[0]
            stack = []
            nonlocal ans
            for idx,val in enumerate(heights):
                while stack and heights[stack[-1]]>val:
                    top = stack.pop()
                    ans = max(ans, heights[top]*(idx-(stack[-1]+1)))
                stack.append(idx)
            
        if matrix == []:
            return 0

        Nrow, Ncol = len(matrix), len(matrix[0])
        heights = [0]*Ncol

        for i in range(Nrow):
            for j in range(Ncol):
                if matrix[i][j] == '0':
                    heights[j] = 0
                if matrix[i][j] == '1':
                    heights[j] += 1
            _maxRectangle(heights)

        return ans
```
