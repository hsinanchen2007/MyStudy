### 解题思路
此处撰写解题思路
总共有gridSize行，*gridColSize列。
如果两两之间没有接触，那么每个元素应有grid[i][j] * 4 + 2个面。
现在不清楚有旁边有没有接触，那么就要考虑，如果接触的话：
左边(右边)的楼比当前的楼要高，所以当前这个楼没有接触的总共的面就要减grid[i][j] * 2;*2是因为两两接触，两栋都要减。
左边(右边)的楼比较低，所以要减去左边(右边)的楼层高度，即减去grid[i][j-1](grid[i][j+1]) * 2
同理，上下也是一样的
### 代码

```c
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int area = 0;
    for(int i = 0; i < gridSize; i++)
    {
        for(int j = 0; j < *gridColSize; j++)
        {
            if(grid[i][j])
            {
                area = area + grid[i][j] * 4 + 2;
                if(i < gridSize - 1 && grid[i + 1][j])
                    area -= ((grid[i][j] > grid[i+1][j]) ? grid[i+1][j] : grid[i][j]) * 2;
                if(j < *gridColSize - 1 && grid[i][j+1])
                    area -= ((grid[i][j] > grid[i][j+1]) ? grid[i][j+1] : grid[i][j]) * 2;
            }
        }
    }
    return area;
}
```