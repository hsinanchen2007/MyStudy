（执行用时:128ms,在所有Python提交中击败了96.61%的用户；内存消耗:14.4MB,在所有Python提交中击败了17.20%的用户）

简单来说就是上下左右的蔓延开来，是1则填充为-1，如果某个点上下左右都是-1或者0或者是边界了，那么就停止了。

    def maxAreaOfIsland(self, grid):
      def f(i,j):
          if i!=0:
              if grid[i-1][j]==1:
                  grid[i-1][j]=-1
                  res.append(1)
                  f(i-1,j)
          if i!=len(grid)-1:
              if grid[i+1][j]==1:
                  grid[i+1][j]=-1
                  res.append(1)
                  f(i+1,j)
          if j!=0:
              if grid[i][j-1]==1:
                  grid[i][j-1]=-1
                  res.append(1)
                  f(i,j-1)
          if j!=len(grid[0])-1:
              if grid[i][j+1]==1:
                  grid[i][j+1]=-1
                  res.append(1)
                  f(i,j+1)

      res_max=0
      for i in range(len(grid)):
          for j in range(len(grid[0])):
              if grid[i][j] in (0,-1):
                  continue
              else:
                  res=[1]
                  grid[i][j]=-1
                  f(i,j)
                  if len(res)>res_max:
                      res_max=len(res)

      return res_max