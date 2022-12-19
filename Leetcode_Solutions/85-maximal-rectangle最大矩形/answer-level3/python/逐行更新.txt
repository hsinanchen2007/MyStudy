### 解题思路
刚开始看到这道题没有思路，参考了评论区的思路和代码
这道题关键的思路就是：逐行判断，每一行更新一个新的列表再调用84题的解法，这里的列表更新方法是，如果新的一行为0，则该位置为0，如果为1，则在该位置+1，这样可以保证每一行的列表都是目前可以有的最大面积。

### 代码

```python
class Solution(object):
    def maximalRectangle(self, matrix):
        res = 0
        if len(matrix)==0:
            return res
        m,n = len(matrix),len(matrix[0])
        heights = [0]*n
        for i in range(m):
            for j in range(n):
                if matrix[i][j]=="0":
                    heights[j] = 0
                else:
                    heights[j] = heights[j]+1
            res = max(res,self.largestRectangleArea(heights))
        return res
    def largestRectangleArea(self, heights):
        heights.append(0)
        stack = []
        res = 0
        for i in range(len(heights)):
            while(stack and heights[stack[-1]]>heights[i]):
                temp = heights[stack[-1]]
                stack.pop()
                res = max(res,temp*(i-stack[-1]-1 if stack else i))
            stack.append(i)
        return res
```