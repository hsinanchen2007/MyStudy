深度遍历/递归

```
class Solution:
	def minPathSum(self, grid) -> int:
		dirction = [[1,0],[0,1]]
		m = len(grid)
		n = len(grid[0])
		self.minsum = 100000000
		def dfs(i,j,tempsum):
			if i==m-1 and j==n-1:
				self.minsum = min(self.minsum,tempsum)
			for h in range(2):
				if i+dirction[h][0]<m and j+dirction[h][1]<n :
					a = i+dirction[h][0]
					b = j+dirction[h][1]
					tempsum1 = tempsum + grid[a][b]
					dfs(a,b,tempsum1)
		dfs(0,0,grid[0][0])
		return self.minsum
```
动态规划
```
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if(not grid):
            return 0
        m=len(grid)
        n=len(grid[0])
        for i in range(1,n):
            grid[0][i]+=grid[0][i-1]
        for j in range(1,m):
            grid[j][0]+=grid[j-1][0]
        for x in range(1,m):
            for y in range(1,n):
                grid[x][y]+=min(grid[x-1][y],grid[x][y-1])
        return grid[-1][-1]

```
