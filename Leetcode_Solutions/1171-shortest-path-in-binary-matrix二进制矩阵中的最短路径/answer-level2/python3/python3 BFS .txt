### 解题思路：
类似走迷宫的解法，先找到第 `i` 步，然后把它周围走一步能到的点的位置都 `append` 到 `list` 里。这样就可以得到走 `i+1` 步的情况下，能走到的所有位置。`visited` 矩阵初始化全部为 `0`，然后每次赋值我就把走到这个点需要走几步赋值给它。

如果下一个点就是终点，那就直接返回需要走的 `step` 就是最短路径的长度了。这个长度肯定是最短的了，因为如果有比它还短的路径，那在之前的搜索过程中就会发现了。
### 代码：

```python [-Python]
class Solution(object):
    def shortestPathBinaryMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n, m = len(grid), len(grid[0])
        visited = [[0] * m for _ in range(n)]
        if n==1 and m==1:
            return 1
        if grid[0][0]==1 or grid[n-1][m-1]==1:
            return -1
        x=[-1,-1,-1, 0, 0, 1, 1, 1]
        y=[-1, 0, 1,-1, 1,-1, 0, 1]
        stack=[(0,0)]
        visited[0][0]=1
        step=1
        temp_list=[]
        while len(stack):
            cur_x,cur_y=stack.pop()
            step=visited[cur_x][cur_y]
            step+=1
            for i in range(8):
                next_x,next_y=cur_x+x[i],cur_y+y[i]
                if next_x==n-1 and next_y==m-1:
                    return step
                if 0<=next_x<=n-1 and 0<=next_y<=m-1 and grid[next_x][next_y]==0 and visited[next_x][next_y]==0:
                    temp_list.append((next_x,next_y))
                    visited[next_x][next_y]=step
                else:
                    continue
            if len(stack)==0:
                stack=temp_list.copy()
                temp_list=[]

        return -1

```

>执行用时 :
604 ms，在所有 Python3 提交中击败了 100.00% 的用户


>内存消耗 :
13.2 MB，在所有 Python3 提交中击败了 100.00% 的用户
