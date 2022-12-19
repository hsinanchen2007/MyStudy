### 解题思路
往返可以看做两路同时从起点出发到达终点
对于两路同时出发，有坐标关系x1+y1=x2+y2，从而把4维简化为3维

### 代码

```c
/*dp[x1][y1][x2][y2], y2 = x1+y1-x2*/

int calc_iter(int ** grid, int n, int x1, int y1, int x2, int dp[50][50][50])
{
    int ret = 0;
    int res1 = -2;
    int res2 = -2;
    int res3 = -2;
    int res4 = -2;
    int y2 = x1+y1-x2;
    int inc = 0;
    
    if ((x1 == n-1) && (y1 == n-1) && (x2 == n-1))
    {
        return *(grid[n-1]+n-1);
    }
    
    if (-2 != dp[x1][y1][x2])
    {
        return dp[x1][y1][x2];
    }
    
    if (x1 == x2)
    {
        if (-1 == *(grid[x1]+y1))
        {
            dp[x1][y1][x2] = -1;
            return -1;
        }
        inc = *(grid[x1]+y1);
    }
    else
    {
        if ((-1 == *(grid[x1]+y1)) || (-1 == *(grid[x2]+y2)))
        {
            dp[x1][y1][x2] = -1;
            return -1;
        }
        inc = *(grid[x1]+y1) + *(grid[x2]+y2);
    }
    
    if ((x1 < n-1) && (x2 < n-1))
    {
        res1 = calc_iter(grid, n, x1+1, y1, x2+1, dp);
        if (-1 != res1)
        {
            res1 += inc;
        }
    }
    
    if ((x1 < n-1) && (y2 < n-1))
    {
        res2 = calc_iter(grid, n, x1+1, y1, x2, dp);
        if (-1 != res2)
        {
            res2 += inc;
        }
    }
    
    if ((y1 < n-1) && (y2 < n-1))
    {
        res3 = calc_iter(grid, n, x1, y1+1, x2, dp);
        if (-1 != res3)
        {
            res3 += inc;
        }
    }
    
    if ((y1 < n-1) && (x2 < n-1))
    {
        res4 = calc_iter(grid, n, x1, y1+1, x2+1, dp);
        if (-1 != res4)
        {
            res4 += inc;
        }
    }
    
    ret = res1 > res2 ? res1 : res2;
    ret = ret > res3 ? ret : res3;
    ret = ret > res4 ? ret : res4;
    
    dp[x1][y1][x2] = ret;

    return ret;
}

int cherryPickup(int** grid, int gridSize, int* gridColSize){
    int ret = 0;
    int dp[50][50][50] = {0};
    int i = 0;
    int j = 0;
    int k = 0;
    
    for (i = 0; i < gridSize; i++)
    {
        for (j = 0; j < gridSize; j++)
        {
            for (k = 0; k < gridSize; k++)
            {
                dp[i][j][k] = -2;
            }
        }
    }
    
    ret = calc_iter(grid, gridSize, 0, 0, 0, dp);
    
    if (-1 == ret)
    {
        ret = 0;
    }
    
    return ret;
}


```