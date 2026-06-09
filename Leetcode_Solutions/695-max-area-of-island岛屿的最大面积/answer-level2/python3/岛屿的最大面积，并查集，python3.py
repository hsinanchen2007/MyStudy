### 解题思路
并查集的代码结构都是差不多的，写好union函数最重要，为避免时间复杂度可能变高，一般需要维护一个rank列表来做路径压缩。
```
def find():
    code

def union():
    code

def union_find():
    code
```
可参考[冗余链接](https://leetcode-cn.com/problems/redundant-connection/solution/rong-yu-lian-jie-bing-cha-ji-python3-by-cumt_scx/),[除法求值](https://leetcode-cn.com/problems/evaluate-division/solution/chu-fa-qiu-zhi-bing-cha-ji-python3-by-cumt_scx/),[被围绕的区域](https://leetcode-cn.com/problems/surrounded-regions/solution/bei-wei-rao-de-qu-yu-bing-cha-ji-lu-jing-ya-suo-py/)
### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.res = 0

        grid = [i+[0] for i in grid]+[[0 for _ in range(len(grid[0])+1)]]
        parent = [[[i, j] if grid[i][j]==1 else [-1, -1] for j in range(len(grid[0]))] for i in range(len(grid))]
        rank = [[1 for j in range(len(grid[0]))] for i in range(len(grid))]
        area = [[1 if grid[i][j]==1 else 0 for j in range(len(grid[0])-1)] for i in range(len(grid)-1)]

        def find(x):
            if parent[x[0]][x[1]] == [x[0], x[1]]:
                return [x[0], x[1]]
            else:
                return find(parent[x[0]][x[1]])
        
        def union(x, y):
            if grid[x[0]][x[1]]==0 or grid[y[0]][y[1]]==0:
                return
            xroot = find(x)
            yroot = find(y)
            if xroot==yroot:
                return
            else:
                if rank[xroot[0]][xroot[1]]>rank[yroot[0]][yroot[1]]:
                    parent[yroot[0]][yroot[1]]=parent[xroot[0]][xroot[1]]
                    area[xroot[0]][xroot[1]] += area[yroot[0]][yroot[1]]
                    self.res = max(self.res, area[xroot[0]][xroot[1]])
                else:
                    parent[xroot[0]][xroot[1]]=parent[yroot[0]][yroot[1]]
                    rank[yroot[0]][yroot[1]]+=1
                    area[yroot[0]][yroot[1]] += area[xroot[0]][xroot[1]]
                    self.res = max(self.res, area[yroot[0]][yroot[1]])

        def union_find():
            for i in range(len(grid)-1):
                for j in range(len(grid[i])-1):
                    if grid[i][j]==1:
                        self.res = max(1, self.res)
                    union([i, j], [i+1, j])
                    union([i, j], [i, j+1])
            return self.res

        return union_find()
```