### 解题思路：简单粗暴，用深度优先搜索，把所有4邻域内不为零的位置压入栈内，并将该位置值置0，防止重复搜索。因为只是标记了已搜索区域，并没有直接消除，所以耗时很长。
将当前位置不为0的位置信息压入栈，并置0
当栈不为空
弹出栈顶
面积+1
以栈顶位置为中心搜索，将周围非0位置压入栈，同时置0
当栈空，结束本次循环
计算最大面积


### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        stack = []
        maxArea = 0
        bias=[[0,-1],[0,1],[-1,0],[1,0]]
        for gridi in range(len(grid)):
            for gridj in range(len(grid[gridi])):
                stack = []
                area = 0
                if grid[gridi][gridj] == 1:
                    stack.append([gridi,gridj])
                    grid[gridi][gridj] = 0
                    while stack:
                        [i, j] = stack.pop()
                        area += 1
                        for [bi, bj] in bias:
                            nexti = i+bi
                            nextj = j+bj
                            if 0<=nexti<len(grid) and 0<=nextj<len(grid[0]):
                                if grid[nexti][nextj]==1:
                                    grid[nexti][nextj]=0
                                    stack.append([nexti, nextj])
                    if maxArea < area:
                        maxArea = area
        return maxArea
```