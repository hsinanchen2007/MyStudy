### 解题思路
思路: 分析题目，对于每个海洋，距离他最近的陆地为该海洋距陆地的距离。题目要求出海洋到陆地最远的距离。那么也就可以看作是求陆地到海洋最远的距离，我们以每个陆地为起始点，向外扩散找到最远的海洋。注意：以每个海洋为起始点找最远陆地是不行的，因为题目说了与每个海洋最近的陆地才是该海洋到陆地的距离。

### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        
        queue = []
        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    queue.append((i,j))
        #全为陆地，全为海洋返回
        if len(queue)==0 or len(queue)==m*n:
            return -1
        dire = [(0,1),(0,-1),(1,0),(-1,0)]
        step = -1    #没有提前return，在最后清空queue后，step还会+1，所以一开始设置为-1。
        while queue:
            #下面一句用于计算当前step的点
            for _ in range(len(queue)):
                i,j = queue.pop(0)
                for d in dire:
                    x = i+d[0]
                    y = j+d[1]
                    if 0<=x<m and 0<=y<n and grid[x][y]==0:
                        queue.append((x, y))
                        grid[x][y]=1
            step+=1
        return step
```