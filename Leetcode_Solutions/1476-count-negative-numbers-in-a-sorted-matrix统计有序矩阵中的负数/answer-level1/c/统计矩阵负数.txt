### 解题思路
gridSize 是行数
gridColSize 是列数（不知道为什么以指针方式传进来）
grid 就是二维数组

### 代码

```c


int countNegatives(int** grid, int gridSize, int* gridColSize){
    int sum=0;
    int i;
    for(i=0;i<gridSize;++i)
    {
        int j;
        for(j=0;j<*gridColSize;++j)
            if(grid[i][j]>=0)
            ++sum;
    }
    return gridSize**gridColSize-sum;
}
```