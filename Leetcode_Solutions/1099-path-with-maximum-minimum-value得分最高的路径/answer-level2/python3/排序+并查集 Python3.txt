**思路：**

本题有多种方法，比如DP或二分DFS。本题解采用与周赛第三题[彼此熟识的最早时间](https://leetcode-cn.com/contest/biweekly-contest-3/problems/the-earliest-moment-when-everyone-become-friends/)同样的方法，排序加并查集。初始答案`ans`是第一个格子和最后一个格子两者之间的最小值`min(A[0][0], A[R - 1][C - 1])`，先将所有格子按照`(数值, 行, 列)`组成的三元组，加进一个`list`里面，然后对这个`list`进行排序。按照格子值从大到小进行遍历，没读取一个格子，就把格子进行染色，用集合`s`来表示已经染色的格子集合，然后检查该格子的上下左右是否也经过染色，如果也染过色，那么将该格子加入到同一个并查集里。直到第一个格子和最后一个格子属于同一个并查集，遍历结束。在遍历过程中不断更新`ans`，遍历结束后返回`ans`即可。

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
    def maximumMinimumPath(self, A: List[List[int]]) -> int:
        R = len(A)
        C = len(A[0])
        n = R * C
        d = DSU(n)
        s = set()
        points = []
        for i in range(R):
            for j in range(C):
                points.append((A[i][j], i, j))
        points.sort()
        ans = min(A[0][0], A[R - 1][C - 1])
        s.add((0, 0))
        s.add((R - 1, C - 1))
        while d.find(0) != d.find(n - 1):
            p, x, y = points.pop()
            ans = min(ans, p)
            for i, j in [(x - 1, y), (x, y - 1), (x + 1, y), (x, y + 1)]:
                if (i, j) in s:
                    d.union(x * C + y, i * C + j)
                s.add((x, y))
        return ans
```