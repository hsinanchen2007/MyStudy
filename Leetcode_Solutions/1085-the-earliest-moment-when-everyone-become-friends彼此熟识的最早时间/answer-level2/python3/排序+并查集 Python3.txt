**思路：**

由于题目要求返回圈子里所有人之间都熟识的最早时间，所以首先要把`logs`按照时间顺序排序。本题的实质是在一个无向图中，有`N`个结点，每个`log`是连通两个结点的一条边，求按照时间顺序在图中加边，最早什么时候能把整个图合成一个连通分量。关于连通分量，可以用并查集来解决，自己写一个并查集类，记录每个结点的父结点，和该结点连通分量的大小。每次读入一个`log`，把`log`中两个结点所属集合合并，然后检测一下合并之后的集合大小是不是等于`N`，即所有人之间都熟识，如果等于`N`，则直接返回该`log`的时间。

**代码：**

```python
class DSU(object):
    def __init__(self, n):
        self.par = [i for i in range(n)]
        self.sz = [1] * n

    def find(self, x):
        if self.par[x] != x:
            self.par[x] = self.find(self.par[x])
        return self.par[x]

    def union(self, x, y):
        xr, yr = self.find(x), self.find(y)
        if xr == yr:
            return
        if self.sz[xr] < self.sz[yr]:
            xr, yr = yr, xr
        self.par[yr] = xr
        self.sz[xr] += self.sz[yr]


class Solution:
    def earliestAcq(self, logs: List[List[int]], N: int) -> int:
        dsu = DSU(N)
        logs.sort()
        for log in logs:
            a = log[1]
            b = log[2]
            dsu.union(a, b)
            if dsu.sz[dsu.find(a)] == N:
                return log[0]
        return -1
```