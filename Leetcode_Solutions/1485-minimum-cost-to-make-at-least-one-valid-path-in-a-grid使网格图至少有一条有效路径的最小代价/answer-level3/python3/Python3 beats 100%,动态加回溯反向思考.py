### 解题思路
反向思考，从最后一个点开始有多少个点与最后点连通，意即耗费的花费数是0，将这些点归为visieted，最小花费状态，
下一步，遍历这些点，找到花费为1的所有点的位置，局部最小花费状态。
下一步，遍历上一步找到的花费为1的点，变为局部最小状态。
知道找到点0，0为止。
即为局部最优解。
核心思想是动态规划。每次存储找到的新的花费为1的点，作为下一步的点集合。
从到终点为0花费的点开始，依次找花费为1，2，3，的点，直到找到花费为i的点，发现0，0包含在内，极为最小花费。

### 代码

```python3
class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        m,n=len(grid),len(grid[0])
        def dfs(i,j,visited):
            visited.add((i,j))
            if i<0 or i>=m or j<0 or j>=n:
                return 
            for num,(x,y) in enumerate([(i,j-1),(i,j+1),(i-1,j),(i+1,j)]):
                if x<0 or x>=m or y<0 or y>=n:
                    continue
                if num+1==grid[x][y] and (x,y) not in visited:
                    dfs(x,y,visited)
        visited=set([(m-1,n-1)])
        dfs(m-1,n-1,visited)
        temp=visited.copy()
        count=0
        while (0,0) not in visited:
            count+=1
            last=visited.copy()
            for i,j in temp:
                for num,(x,y) in enumerate([(i,j-1),(i,j+1),(i-1,j),(i+1,j)]):
                    if x<0 or x>=m or y<0 or y>=n:
                        continue
                    if num+1!=grid[x][y] and (x,y) not in visited:
                        dfs(x,y,visited)
            temp=visited-last
        return count

```