### 解题思路
此处撰写解题思路
全局变量 self.count
思路：访问过标志为True,深度优先遍历，一个岛屿 每走一步加1 走完一个岛屿存放到 结果数组 max(结果数组)

### 代码

```python3
class Solution:
    count=0
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        #行
        m=len(grid)
        #列
        n=len(grid[0])
        #  是否访问
        visited=[[False]*n for _ in range(m)]
        # 走的方向 上下 左右
        dirctions=[[-1,0],[1,0],[0,-1],[0,1]]
        # 保存每个岛屿的大小
        resArray=[]

        def DFS(i,j):
            visited[i][j]=True
            for d in dirctions:
                wi,wj=d[0]+i,d[1]+j
                if -1<wi<m and -1<wj<n and not visited[wi][wj] and grid[wi][wj]==1:
                    self.count += 1
                    DFS(wi,wj)

        for i in range(m):
            for j in range(n):
                if not visited[i][j] and grid[i][j]==1:
                    self.count=1
                    DFS(i,j)
                    resArray.append(self.count)
        return max(resArray) if resArray else 0
```