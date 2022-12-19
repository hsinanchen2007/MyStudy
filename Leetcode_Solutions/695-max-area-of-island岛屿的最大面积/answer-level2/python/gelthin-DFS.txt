### 解题思路
最近手感不好，一不小心就写出来 bug. 变量名连续敲错两次，这也怪自己，变量不好好命名，导致经常出错。

我这里相当于设计了一个标记数组，来标记哪些点访问过，哪些点没访问过。
官方题解没有使用标记数组，而是访问过直接把值变为 0. 

##### 与官方题解最大的区别是，在 DFS 之前，我就进行了判断这点是不是要进行 DFS.
而官方题解是把异常情况，例如 下标越界，已经访问过等，在 dfs 函数里面进行处理，这样会比我多递归调用一层。
这样写有好处，少递归一层，但也有坏处，如果外部的判断确实，例如 忘了判断 root==None，而直接
dfs(root), 而dfs 里面有没有判断 root 是否为 None, 就经常导致错误。


### 还有一个注意点，这里是非空二维数组，不一定是矩阵
也就是说每一行的长度可能是不同的
官方题解的代码:

``` python3
for i, l in enumerate(grid): ## 这里的 l 代表一行
            for j, n in enumerate(l):  ## 这里 j 的范围是 len(l)
```

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:

        def dfs(grid, i, j, m, n, mark):
            dx = [0,0,1,-1]
            dy = [1,-1,0,0]
            
            val = 1
            mark[i][j] = True
            for k in range(4):
                nx, ny = i+dx[k], j+dy[k]
                # if 0<=nx<m and 0<=ny<n and grid[nx][ny] == 1 and not mark[i][j]:  #BUG
                # if 0<=nx<m and 0<=ny<n and grid[nx][ny] == 1 and not mark[dx][dy]: # BUG
                if 0<=nx<m and 0<=ny<n and grid[nx][ny] == 1 and not mark[nx][ny]:
                    val += dfs(grid, nx, ny, m, n, mark)
            return val

        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        mark = []  # 记录是否访问过
        for i in range(m):
            mark.append([False]*n)
        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1 and not mark[i][j]:
                    res = max(res, dfs(grid, i, j, m, n, mark))
        return res
        
```