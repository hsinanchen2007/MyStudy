![image.png](https://pic.leetcode-cn.com/1aae4a9347678c0d123e43250f660531a5429cab18c3c141bf225c963d5b1d26-image.png)


```

'''
dfs把连通域枚举出来，然后每一个连通域中的节点和连通域的左上角取相对坐标，然后排序后
的点序列作为hash值，8个hash都没有出现过的形状才认为是第一次出现的形状，统计
不同的形状出现次数
'''

from typing import List
class Solution:

    def dfs(self, i, j, grid: List[List[int]], visited, pos):
        if visited[i][j] or grid[i][j] == 0:
            return

        pos.append((i, j))
        visited[i][j] = 1
        m, n = len(grid), len(grid[0])
        for ii, jj in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]:
            if ii >= 0 and ii < m and jj >= 0 and jj < n:
                self.dfs(ii, jj, grid, visited, pos)

    def getHash(self, data_list):
        min_i, min_j = min([p[0] for p in data_list]), min([p[1] for p in data_list])
        ans = [(i - min_i, j - min_j) for i, j in data_list]
        ans.sort()
        return tuple(ans)

    def numDistinctIslands2(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        visited = [[0 for _ in range(n)] for _ in range(m)]
        hash_rec = set()

        cnt = 0
        for i in range(m):
            for j in range(n):
                if visited[i][j] == 0 and grid[i][j] == 1:
                    pos = []
                    self.dfs(i, j, grid, visited, pos)
                    print(pos)

                    hash_code = [
                        self.getHash([(i, j) for i, j in pos]),
                        self.getHash([(-i, j) for i, j in pos]),
                        self.getHash([(i, -j) for i, j in pos]),
                        self.getHash([(-i, -j) for i, j in pos]),
                        self.getHash([(j, i) for i, j in pos]),
                        self.getHash([(-j, i) for i, j in pos]),
                        self.getHash([(j, -i) for i, j in pos]),
                        self.getHash([(-j, -i) for i, j in pos])
                    ]

                    flag = True
                    for k in range(8):
                        if hash_code[k] in hash_rec:
                            flag = False
                    for k in range(8):
                        hash_rec.add(hash_code[k])

                    if flag:
                        cnt += 1
        return cnt

print(Solution().numDistinctIslands2(
[
    [1,1,1,0,0],
    [1,0,0,0,1],
    [0,1,0,0,1],
    [0,1,1,1,0]
]
))
```
