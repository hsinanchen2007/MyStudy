
每次计算出新增面积，之后累加即可。
备注：系统测试预期有bug：
   **输入[[1,1]]系统输出预期为6，其实应该为10**


#define MIN(a,b) ((a)<(b)?(a):(b))

int surfaceArea(int** grid, int gridSize, int* gridColSize){

    if(gridSize == 0)
    {
        return 0;
    }
    int i ,j;
    int s[50][50] = {0};
    int sum = 0;

    s[0][0] = grid[0][0]*4 + 2;

    for(i=0;i<gridSize;i++)
    {
        for(j=0;j<gridColSize[i];j++)
        {
            if(0 == grid[i][j])
            {
                s[i][j] = 0;
                continue;
            }

            if(i == 0 && j != 0)
            {
                 s[i][j] = (grid[i][j]*4 + 2) - 2 * MIN(grid[i][j], grid[i][j-1]);
            }
            else if(j == 0 && i != 0)
            {
                s[i][j] = (grid[i][j]*4 + 2) - 2 * MIN(grid[i][j],grid[i-1][j]);
            }
            else if(i!=0 && j!=0)
            {
                s[i][j] = (grid[i][j]*4 + 2) - 2 * MIN(grid[i][j], grid[i][j-1]) - 2 * MIN(grid[i][j],grid[i-1][j]); 
            }
          // printf("s[%d][%d]=%d\r",i,j,s[i][j]);
        }
    }

    for(i=0;i<gridSize;i++)
    {
        for(j=0;j<gridColSize[i];j++)
        {
            sum += s[i][j];
        }
    }
  
  return sum;
}