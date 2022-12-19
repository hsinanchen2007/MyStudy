### 解题思路
参考到解题区大佬的解法，写一个python版本的，详情请看注释。

### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
#两次动态规划，先从左上到右下，再从右下到左上,如果用 f(x, y)记录左上方的 DP 结果，g(x, y) 记录右下方的DP结果可行吗？ 
#答案是不可行。因为考虑距离点 (x, y)最近的点可能既不来自左上方，也不来自右下方，比如它来自右上方或者左下方
#所以要用到第一次dp的结果。

        m,n=len(grid),len(grid[0])
        dp=[[float("inf")]*(n+2) for _ in range(m+2)] #dp数组，dp[i][j]表示i，j位置的海洋离左上的陆地的最小距离
        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    dp[i+1][j+1]=0           #初始化数组
        #从左上向右下dp填表，得到的是离海洋距离最短的路径要么来自左方，要么来自上方
        for i in range(1,m+1):
            for j in range(1,n+1):
                if grid[i-1][j-1]==0:
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1  #要么来自左边，要么来自上边

        #从右下往左上dp填表,注意这里用到了上一个dp的结果，
        #因为第一次填表已经考虑到要么来自左方或者上方，这次再此基础上再考虑右方下方，
        #这样就把方位全部考虑完了
        for i in range(m,0,-1):
            for j in range(n,0,-1):
                if grid[i-1][j-1]==0:
                    dp[i][j]=min(dp[i+1][j]+1,dp[i][j+1]+1,dp[i][j])
        
        #计算结果
        ans=0
        for i in range(1,m+1):
            for j in range(1,n+1):
                ans=max(ans,dp[i][j])
        return ans if ans and ans!=float("inf") else -1





class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        # 以陆地为标准的多源广度优先
        from collections import deque
        directions=[(0,1),(1,0),(-1,0),(0,-1)]  #方向数组
        m,n=len(grid),len(grid[0])
        deque=deque()   #零时双端队列
        #遍历数组，将陆地添加进去
        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    deque.append((i,j,0))  #这里添加一个三元组，0表示当前点是在第几层，现在在第0层
        if len(deque)==0 or len(deque)==m*n:  #这里排除全1或者全0情况
            return -1
        ans=0
        while deque:
            x,y,count=deque.popleft() #广度优先，先进先出
            for d in directions:      #遍历四个方向
                nx,ny=d[0]+x,d[1]+y
                if 0<=nx<m and 0<=ny<n and grid[nx][ny]==0:
                    deque.append((nx,ny,count+1))  
                    grid[nx][ny]=1
            ans=count
        return ans
        

        

        

        

        


            






                        


        

```