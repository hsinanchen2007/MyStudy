### 解题思路
遍历每个位置 与前后左右比较判断加多少面积即可

### 代码

```c
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int sum=0;
    for(int i=0;i<gridSize;i++) // 遍历每一行
    {
        for(int j=0;j<gridSize;j++) //遍历每一行的元素
        {
            //上下侧面积
            if(grid[i][j]>0) sum+=2;     // 上下面积各加1.

            //左侧
            if(j==0)   // 每行第一列，其左侧无阻挡
            {
                sum+=grid[i][j];
            }

            if(j>0&&grid[i][j]>grid[i][j-1])  //有左侧高出部分
            {
                sum+=grid[i][j]-grid[i][j-1];
            }

            //右侧
            if(j==gridSize-1) sum+=grid[i][j];  //最右侧

            if(j<gridSize-1&& grid[i][j]>grid[i][j+1]) 
            {
                sum+=grid[i][j]-grid[i][j+1];
            }
            //前侧
            if(i==(gridSize-1)) 
            {
                sum+=grid[i][j];
            }

            if(i<gridSize-1 && grid[i][j]>grid[i+1][j])
            {
                sum+=grid[i][j]-grid[i+1][j];
            }

            //后侧
            if(i==0) sum+=grid[i][j];

            if(i>0&&grid[i][j]>grid[i-1][j])
            {
                sum+=grid[i][j]-grid[i-1][j];
            }
        }
    }

    return sum;

}
```