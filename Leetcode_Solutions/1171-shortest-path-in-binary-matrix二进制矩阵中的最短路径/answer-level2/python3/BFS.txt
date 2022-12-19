### 解题思路
典型BFS题目

参考: https://github.com/CyC2018/CS-Notes/blob/master/notes/Leetcode%20%E9%A2%98%E8%A7%A3%20-%20%E6%90%9C%E7%B4%A2.md#1-%E8%AE%A1%E7%AE%97%E5%9C%A8%E7%BD%91%E6%A0%BC%E4%B8%AD%E4%BB%8E%E5%8E%9F%E7%82%B9%E5%88%B0%E7%89%B9%E5%AE%9A%E7%82%B9%E7%9A%84%E6%9C%80%E7%9F%AD%E8%B7%AF%E5%BE%84%E9%95%BF%E5%BA%A6

每一层遍历的节点都与根节点距离相同。设 di 表示第 i 个节点与根节点的距离，推导出一个结论：对于先遍历的节点 i 与后遍历的节点 j，有 di <= dj。利用这个结论，可以求解最短路径等 最优解 问题：第一次遍历到目的节点，其所经过的路径为最短路径。应该注意的是，使用 BFS 只能求解无权图的最短路径，无权图是指从一个节点到另一个节点的代价都记为 1。


### 代码

```python3
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        #最短路径, BFS直接一层一层得结果
        if grid[0][0] == 1 or grid[-1][-1]:
            return -1

        def connected(point): #生成和该点链接的所有可连通(==0)的点
            res = []
            #8方向:
            move = [(1,1),(0,1),(-1,-1),(-1,0),(-1,1),(0,-1),(1,-1),(1,0)]
            for x,y in move:
                new_point_x = point[0] + x
                new_point_y = point[1] + y
                n = len(grid)
                if new_point_x <0 or new_point_y <0 or new_point_x >=n or new_point_y >=n:#排除过界的
                    continue
                if grid[new_point_x][new_point_y] ==0: #第一次提交, 这里写成了1, 所以遇到问题莫慌, 相信自己!先排出小失误.
                    res.append((new_point_x,new_point_y))
            return res

        def bfs(grid,s):
            bfs_queue = [s]
            seen = set()
            seen.add(s)
            parent = {s:None}
            while bfs_queue:
                point = bfs_queue.pop(0)
                connects = connected(point)
                for new_p in connects:
                    if new_p not in seen:
                        parent[new_p] = point
                        bfs_queue.append(new_p)
                        seen.add(new_p)#第二次提交, 这里出了问题,和dijkstra混淆了, BFS的seen是在队列就是seen了.先入队列,代表在之前的层(这样的话,路径也可以尽量短)
            return parent,seen
        
        parent,seen = bfs(grid,(0,0))
        
        
        n = len(grid)
        if (n-1,n-1) not in seen:
            return -1
        count = 1
        p = (n-1,n-1)
        while parent[p] != None:
            p = parent[p]
            count +=1
        return count
```