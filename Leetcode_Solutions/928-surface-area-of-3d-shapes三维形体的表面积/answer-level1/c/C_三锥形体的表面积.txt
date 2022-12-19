### 解题思路
本来以为会有什么曲面积分之类的操作，结果就是一个个方块数面积。

### 代码

```c

int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int i, j, k, res = 0;
    for(i=0; i<gridSize; i++)
        for(j=0; j<gridColSize[i]; j++)
            for(k=0; k<grid[i][j]; k++)
            {
                res += 6;
                // 下面相邻
                if(k>0)
                    res -= 2;
                // 前面相邻
                if(i>0 && grid[i-1][j]>k)
                    res -= 2;
                // 左面相邻
                if(j>0 && grid[i][j-1]>k)
                    res -= 2;
            }
    return res;
}

```