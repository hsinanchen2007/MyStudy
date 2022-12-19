### 解题思路
此处撰写解题思路

### 代码

```c
#define MIN(X,Y) (X>Y ? Y:X)
int surfaceArea(int** grid, int gridSize, int* gridColSize){
int row = gridSize;
int col = *gridColSize;
int sum  = 0;
int temp = 0;
for(int i = 0;i<row;i++)
    {
       for(int j = 0;j<col;j++)
       {
          sum  = sum+6*grid[i][j];//总数
          if(grid[i][j]>=2)         //大于2的减去重叠面
          sum  = sum - 2*(grid[i][j] -1);
          if(j<col-1)                //同一行重叠减较小重叠面
          {
          temp =  MIN(grid[i][j],grid[i][j+1]);
          sum  = sum - temp*2;
          }
          if(i<row-1)           //同一列重叠减较小重叠面
          {
          temp = MIN(grid[i+1][j],grid[i][j]);
          sum  = sum - temp*2;
          }

       }
        
    }

return sum;

}
```