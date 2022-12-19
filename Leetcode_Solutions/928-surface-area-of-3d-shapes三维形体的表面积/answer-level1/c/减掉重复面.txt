大概就是每个六面，减去黏连的面，有个问题就是为啥加的后面和右面不能取等（i+1<== gridSize就不对了）。
int surfaceArea(int** grid, int gridSize, int* gridColSize)
{
    int sum = 0;
    int hold = 0;
    int i, j;
    for (i = 0; i <  gridSize; i++)
    {
        for (j = 0; j < *gridColSize; j++)
        {
            sum += (grid[i][j] * 6);
            if (grid[i][j] > 1)
                sum -= 2*(grid[i][j]-1);
            if(i-1>=0)
            {
                sum-=(grid[i-1][j]<grid[i][j] ? grid[i-1][j]:grid[i][j]);
            }
            if(j-1>=0)
            {
                sum-=(grid[i][j-1]<grid[i][j] ? grid[i][j-1]:grid[i][j]);
            }
            if(i+1< gridSize)
            {
                sum-=(grid[i+1][j]<grid[i][j] ? grid[i+1][j]:grid[i][j]);
            }
            if(j+1< *gridColSize)
            {
                sum-=(grid[i][j+1]<grid[i][j] ? grid[i][j+1]:grid[i][j]);
            }
        }
    }
    return sum;
}