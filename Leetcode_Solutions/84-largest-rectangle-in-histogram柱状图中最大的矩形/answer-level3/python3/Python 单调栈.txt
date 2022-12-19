### 解题思路
单调栈O(N)解决

### 代码

```python3
class Solution:
    def largestRectangleArea(self,heights):
        if heights == None or heights == []:
            return 0

        stack = []
        maxArea = 0
        for i in range(len(heights)):
            while stack != [] and heights[i] <= heights[stack[-1]]:
                pp = stack.pop()
                left = -1 if stack == [] else stack[-1]
                right = i
                maxArea = max(maxArea, (right-left-1)*heights[pp])
            stack.append(i)

        while stack != []:
            pp = stack.pop()
            
            left = -1 if stack == [] else stack[-1]
            maxArea = max(maxArea, (len(heights)-left-1)*heights[pp])
        return maxArea


```