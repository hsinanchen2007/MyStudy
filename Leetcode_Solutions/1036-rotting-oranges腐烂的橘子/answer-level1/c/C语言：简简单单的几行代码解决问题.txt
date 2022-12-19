1. 在一次遍历中（也就是一分钟内），先让坏橘子周围的好橘子变坏。
2. 然后检查是否有好橘子变坏，如果有就行下一次遍历，如果没有就说明（有的好橘子是不可能变坏）。
3. 重复步骤2，直到好橘子数量为零。
```
int orangesRotting(int** grid, int gridRowSize, int *gridColSizes) {
    int good = 0, bad = 0, t = 0;
    for(int i = 0; i < gridRowSize; i++)
        for(int j = 0; j < gridColSizes[0]; j++)
        {
            if     (grid[i][j] == 1) good++;//记录好橘子数
            else if(grid[i][j] == 2) bad++; //记录坏橘子数
        }
    if(!good) return 0;
    if(!bad) return -1;
    int new_good = good;
    while(new_good) //直到好橘子数为零
    {
        t++;//时间加一
        for(int i = 0; i < gridRowSize; i++)
            for(int j = 0; j < gridColSizes[0]; j++)
                if(grid[i][j] == 2)//检查坏橘子四周
                {
                    if(i && grid[i - 1][j] == 1)                       {grid[i-1][j]   = 3; new_good--;}
                    if(j && grid[i][j - 1] == 1)                       {grid[i]  [j-1] = 3; new_good--;}
                    if(i != gridRowSize - 1 && grid[i + 1][j] == 1)    {grid[i+1][j]   = 3; new_good--;}
                    if(j != gridColSizes[0] - 1 && grid[i][j + 1] == 1){grid[i]  [j+1] = 3; new_good--;}
                }
        for(int i = 0; i < gridRowSize; i++)
            for(int j = 0; j < gridColSizes[0]; j++)
                if(grid[i][j] == 3)  grid[i][j] = 2;//重新变为2，方便下一次检查
        if(new_good == good) return -1;//没有新的橘子变坏
        good = new_good;//还剩的好橘子
    }
    return t;
}
```
