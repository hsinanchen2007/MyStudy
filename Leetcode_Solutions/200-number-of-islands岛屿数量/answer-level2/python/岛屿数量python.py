### 解题思路
将每个1周围的1深度遍历进行变为0的操作
最后累加数目即可

### 代码

```python
class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        m=len(grid)
        if m==0:return 0
        n=len(grid[0])
        def dfs(i,j):
            if i < 0 or i >= m or j < 0 or j >= n:return 0
            if grid[i][j]=='0':return 0
            grid[i][j]='0'
            left=dfs(i,j-1)
            right=dfs(i,j+1)
            head=dfs(i+1,j)
            last=dfs(i-1,j)
            return 1+left+right+head+last
        ans=0
        for i in range(m):
            for j in range(n):
                if grid[i][j]=='1':
                    dfs(i,j)
                    ans=ans+1
        return ans
```