动态规划：二维状态

    def minPathSum(self, grid: List[List[int]]) -> int:
        grid2=[[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
        grid2[-1][-1]=grid[-1][-1]

        k=0
        for i in range(len(grid)-1,-1,-1):
            for j in range(len(grid[0])-1,-1,-1):
                if k==0:
                    k+=1
                    continue
                try:
                    if grid2[i+1][j]<=grid2[i][j+1]:
                        grid2[i][j]=grid2[i+1][j]+grid[i][j]
                    else:
                        grid2[i][j]=grid2[i][j+1]+grid[i][j]
                except:
                    try:
                        grid2[i][j]=grid2[i+1][j]+grid[i][j]
                    except:
                        grid2[i][j]=grid2[i][j+1]+grid[i][j]
        return grid2[0][0]

动态规划：二维状态。（但是不用额外储存状态矩阵，但是没能缩小内存）

    def minPathSum(self, grid: List[List[int]]) -> int:
        for i in range(len(grid)-1,-1,-1):
            for j in range(len(grid[0])-1,-1,-1):
                if i==len(grid)-1 and j==len(grid[0])-1:
                    continue
                elif i==len(grid)-1 and j!=len(grid[0])-1:
                    grid[i][j]+=grid[i][j+1]
                elif i!=len(grid)-1 and j==len(grid[0])-1:
                    grid[i][j]+=grid[i+1][j]
                else:
                    if grid[i][j]+grid[i+1][j]<=grid[i][j]+grid[i][j+1]:
                        grid[i][j]+=grid[i+1][j]
                    else:
                        grid[i][j]+=grid[i][j+1]
        return grid[0][0]
