### 解题思路
首先给原矩阵grid添加了全0的边框，以应对遍历过程中的数组越界（在遍历过程中，只需要将当前位置元素与右边元素和下边元素合并，就可以达到理想效果。所以只需要在grid的右边和下边都加上全0边框即可。由于第一次写代码时是将当前元素与四周元素合并，所有下面代码中grid左边和上边都加上了边框）
新建一个parent矩阵，来存储grid矩阵中每一个元素的根节点（同一个岛屿的每个元素拥有相同的根节点），parent形状与grid一样，并对parent进行初始化如下：
当前位置为1，parent[i][j] = [i, j]；否则parent[i][j] = [-1, -1]

find函数：
如果当前位置为0，返回[-1, -1]
如果当前位置元素的根节点就是自己，返回这个根节点的位置，否则返回父节点的根节点


union函数：
如果i，j位置元素的根节点与m，n位置元素的根节点不一致，则合并这两个元的根节点，使用rank做路径压缩，使得树形结构的边不会过长

union_find函数：
遍历grid，合并当前元素与右边和下边的元素
遍历parent，计算根节点的数量count
返回count

### 代码

```python3
class Solution:
    def numIslands(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        grid = [[0]+i+[0] for i in grid]
        grid = [[0 for _ in range(len(grid[0]))]] + grid + [[0 for _ in range(len(grid[0]))]]
        parent = [[[i, j] if grid[i][j] == '1' else [-1,-1] for j in range(len(grid[0]))] for i in range(len(grid))]
        rank = [[1 for j in range(len(grid[0]))] for i in range(len(grid))]


        def find(i, j):
            if grid[i][j] == '0':
                return [-1, -1]
            else:
                if parent[i][j] == [i, j]:
                    return [i, j]
                else:
                    return find(parent[i][j][0], parent[i][j][1])
        

        def union(i, j, m, n):
            xroot = find(i, j)
            yroot = find(m, n)
            if xroot != yroot:
                if rank[xroot[0]][xroot[1]] > rank[yroot[0]][yroot[1]]:
                    parent[xroot[0]][xroot[1]] = yroot
                    rank[yroot[0]][yroot[1]] += 1
                else:
                    parent[yroot[0]][yroot[1]] = xroot
                    rank[xroot[0]][xroot[1]] += 1

            
        def union_find():
            for i in range(len(grid)):
                for j in range(len(grid[0])):
                    if grid[i][j] == '1':
                        if grid[i+1][j] == '1':
                            union(i, j, i+1, j)
                        if grid[i][j+1] == '1':
                            union(i, j, i, j+1)
            count = 0
            for i in parent:
                print(i)
            for i in range(1, len(parent)-1):
                for j in range(1, len(parent[i])-1):
                    if parent[i][j] == [i, j]:
                        count += 1
    
            return count
        
        return union_find()
```