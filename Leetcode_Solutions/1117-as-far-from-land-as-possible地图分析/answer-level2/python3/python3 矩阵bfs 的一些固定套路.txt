### 解题思路
此处撰写解题思路
一开始的思路想的很简单，好久没有做这个bfs题目了， 反应有点慢，看完题目先反应的是先求 一片海洋到最近陆地的距离，再求 所有海洋到最近陆地区域距离的最大值。
然后就有了下面的暴力破解的方式，但是时间肯定通不过，其实想到这个向四周扩散，一层一层的，就应该想到bfs了。
一道典型的bfs题目把，然后就是这个是以陆地为原型的，为什么呢？ 距离陆地区域最远的海洋区域是是哪一个吗？
所以就是找海洋区域，以陆地为原点，向四周一层层扩散，走过的地方标记一下，直到没法走了，说明走到距离所有陆地都最远的海洋区域了。
而这个曼哈顿距离，在这里的体现就是走一层就是加1的距离。
这里的neighbour函数在矩阵的bfs当中向四周扩散遍历可以作为固定函数使用。

之后也尝试dfs，但是之前的那个思路，没想到怎么写，然后返回值总是不对，就没写出来，搁置了。

### 代码

```python3
from collections import deque
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        # BFS 陆地开始往海洋方向扩散
        n = len(grid)

        q = deque()
        for i in range(n):
            for j in range(n):
                if grid[i][j]==1:
                    q.append((i,j))
        if len(q)==0 or len(q)==n*n:
            return -1
        
        def neighbour(r,c):
            for nr,nc in ((r-1,c),(r+1,c),(r,c-1),(r,c+1)):
                if 0<=nr<n and 0<=nc<n:
                    yield (nr,nc)

        distance=-1
        while q:
            distance+=1
            size = len(q)
            for i in range(size):
                r,c = q.popleft()
                for nr,nc in neighbour(r,c):
                    if grid[nr][nc]==0:
                        grid[nr][nc]=2  # 访问过的不在访问
                        q.append((nr,nc))
        return distance



        # dfs
        # n = len(grid)

        # def neighbour(r,c):
        #     for nr,nc in ((r-1,c),(r+1,c),(r,c-1),(r,c+1)):
        #         if 0<=nr<n and 0<=nc<n:
        #             yield (nr,nc)
        # ans = 0
        # def travel(i,j,visited,depth=0):
        #     if (i,j) in visited:
        #         return depth
        #     if grid[i][j]==1:
        #         return depth
        #     visited.add((i,j))

        #     for r,c in neighbour(i,j):
        #         travel(r,c,visited,depth+1)
        
        # depth = 0
        # visited = set()
        # for i in range(n):
        #     for j in range(n):
        #         if grid[i][j]==0:
        #             travel(i,j)


        # brute force 
        # n = len(grid)

        # ans = 0
        # island = []
        # for i in range(n):
        #     for j in range(n):
        #         if grid[i][j]==1:
        #             island.append((i,j))
        # if len(island) in (0,n*n):
        #     return -1

        # def distance(a,b):
        #     return abs(a[0]-b[0])+abs(a[1]-b[1])
        
        # dis = 0
        # for i in range(n):
        #     for j in range(n):
        #         if grid[i][j]==0:
        #             dis = max(dis,min([distance((i,j),b) for b in island]))
        # return dis if dis else -1

```