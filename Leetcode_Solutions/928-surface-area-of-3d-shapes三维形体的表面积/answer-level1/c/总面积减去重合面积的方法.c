### 解题思路
1. 用总的面积减去重合的面积，得到的就是组合体的表面积
2. 一个正方体六个方向，其中上下两个方向的重合面，只需要用这个公式计算即可，2 * (n - 1), n为点上的正方体个数，那么其余四个面，按照四个方向来，前后左右，对应横纵坐标的 y+1, y-1, x+1, x-1，和相邻的坐标比较每个方向的面数，面数小的则为重合的面，循环相加，得出总的重合面
3. 用总面积减去上下，前后左右的重合面，得到结果

![333333.png](https://pic.leetcode-cn.com/825cbb0b03fd9def05d113ea7654b6a2eb172719e81439ceeeeaf1e06cd6178f-333333.png)



### 代码

```c
#define  MIN(a,b) ((a) > (b) ? (b) : (a))
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int i,j;
    int row = gridSize;
    int col = *gridColSize;
    int sum = 0;
    int sub = 0;

    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            sum += grid[i][j];    

    sum = sum * 6;  //求总面积

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (grid[i][j] > 0)
            {
                sum -= (2 * (grid[i][j] - 1));    //减去每个点的上下重合面
                if (i + 1 < row)   //计算右面
                {
                    if (grid[i][j] != grid[i+1][j])
                    {
                        sub += MIN(grid[i][j],  grid[i+1][j]);
                    }
                    else
                    {
                        sub += grid[i][j];
                    }
                }
                if (j + 1 < col)  //计算前面
                {
                    if (grid[i][j] != grid[i][j+1])   //如果两个面数量不相等，则较小的面即为重合面
                    {
                        sub += MIN(grid[i][j], grid[i][j+1]);
                    }
                    else
                    {
                        sub += grid[i][j];   //相等，则此面完全重合
                    }
                }
                if (i - 1 >= 0)   //计算左面
                {
                    if (grid[i][j] != grid[i-1][j])
                    {
                        sub += MIN(grid[i][j],  grid[i-1][j]);
                    }
                    else
                    {
                        sub += grid[i][j];
                    }
                }
                if (j - 1 >= 0)   //计算后面
                {
                    if (grid[i][j] != grid[i][j-1])
                    {
                        sub += MIN(grid[i][j], grid[i][j-1]);
                    }
                    else
                    {
                        sub += grid[i][j];
                    }
                }
            }
        }
    }
    return sum - sub;
}
```