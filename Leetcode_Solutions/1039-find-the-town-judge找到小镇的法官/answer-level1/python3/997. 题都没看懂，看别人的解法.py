### 解题思路
图解法：用一个二位数组记录每个节点的入度和出度，如果存在入度为0，出度为N-1，则该节点为法官；反之，法官不存在。

### 代码

```python3
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        
        grid = [[0, 0] for i in range(N)]
        print(grid)
        for item in trust:
            grid[item[0]-1][0] += 1
            grid[item[1]-1][1] += 1

        if [0, N-1] in grid:
            return grid.index([0, N-1])+1
        return -1       
```