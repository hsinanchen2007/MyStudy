### 解题思路
这题考察dfs，时间复杂度为O(N)，空间上要有个访问数组，不过可以改变元素值来达到目的，就不用额外的空间了。

### 代码

```python3
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        def search(row,col):
            if 0<=row<m and 0<=col<n and grid[row][col]=="1":
                grid[row][col]="-1"
            else:
                return
            search(row-1,col) #上
            search(row+1,col) #下
            search(row,col-1) #左
            search(row,col+1) #右
        amount = 0
        m = len(grid)
        n = len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j]=="1":
                    amount+=1
                    search(i,j)
        return amount
```