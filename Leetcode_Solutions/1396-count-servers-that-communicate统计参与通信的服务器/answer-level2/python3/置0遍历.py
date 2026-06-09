这题其实看清楚题目，找到规律还是非常简单的
我就是被这个medium难度骗了，马上写了一个dfs，然后发现这里通信的要求其实根本不需要连在一起，可恶

所以思路就是逐个遍历grid，如果grid为1，那么就遍历它所在的行和列，统计出十字架结构中1的个数，每一轮都加上这个十字架结构中的数目即可

两个注意点，一是可以直接用置0的方法去解决重复数数的问题，二是最后如果十字架结构的数目为1，表明是孤立的服务器，应该把它丢弃

上代码：
```
class Solution:
    def bfs(self, x,y,m,n,grid):
        global num
        if(grid[x][y] == 0):
            return 
        grid[x][y] = 0
        num += 1
        for i in range(m):
            self.bfs(i,y,m,n,grid)
            
        for j in range(n):
            self.bfs(x,j,m,n,grid)
  
    def countServers(self, grid: List[List[int]]) -> int:
        
        m = len(grid)
        n = len(grid[0])
        
        ans = 0
        
        for i in range(m):
            for j in range(n):
                if(grid[i][j] == 1):
                    global num
                    num = 0
                    self.bfs(i,j,m,n,grid)
                    if(num == 1):
                        num = 0
                    ans += num
        
        return ans
        
        
```
