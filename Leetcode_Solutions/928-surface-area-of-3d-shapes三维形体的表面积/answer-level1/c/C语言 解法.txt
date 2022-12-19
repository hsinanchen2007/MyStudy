
### 代码

```c
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int i,j;
    int sum = 0; // 记录总表面积
    for(i=0;i<gridSize;i++)
    {
        for(j=0;j<*gridColSize;j++)
        {
            int x = grid[i][j];
            if(x==0) // 当放置的正方体数为0时，进行下一个循环
                continue;
            sum= sum + (x*6 - (x-1)*2); // 加上这一摞正方体的表面积
            if(i!=0) // 判断这摞正方体的下边是否存在正方体
            {
                sum = sum - (x<grid[i-1][j]?x:grid[i-1][j])*2; // 将覆盖的面积减去
            }
            if(j!=0)// 判断这摞正方体的左边是否存在正方体
            {
                sum = sum - (x<grid[i][j-1]?x:grid[i][j-1])*2; // 将覆盖的面积减去
            }
        }
    }
    return sum;
}
```