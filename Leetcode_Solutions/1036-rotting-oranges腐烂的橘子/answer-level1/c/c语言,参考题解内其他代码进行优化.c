### 解题思路
将第一次的感染数设为t=2，然后遍历所有可感染目标，然后记录最初时好橘子与坏橘子数；
对坏橘子目标（值等于t的数为坏橘子）进行逐个遍历，将遍历的每一个坏橘子的可感染目标设为t+1并对最初记录的good值减1,然后下一次遍历时就只需要遍历上一次感染的橘子就可以了。

### 代码

```c
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int good=0,bad=0,t=2,q=0;//t为坏橘子代号，q计算时间
    for(int i = 0; i < gridSize; i++)
        for(int j = 0; j < gridColSize[0]; j++)
        {
            if     (grid[i][j] == 1) good++;//记录好橘子数
            else if(grid[i][j] == 2) bad++; //记录坏橘子数
        }
    if(!good) return 0;
    if(!bad) return -1;
    int new_good = good;
    while(new_good) //直到好橘子数为零
    {
        q++;//时间加一
        for(int i = 0; i < gridSize; i++)
            for(int j = 0; j < gridColSize[0]; j++)
                if(grid[i][j] == t)//检查坏橘子四周
                {
                    if(i && grid[i - 1][j] == 1)                       {grid[i-1][j]   = t+1; new_good--;}
                    if(j && grid[i][j - 1] == 1)                       {grid[i]  [j-1] = t+1; new_good--;}
                    if(i != gridSize - 1 && grid[i + 1][j] == 1)    {grid[i+1][j]   = t+1; new_good--;}
                    if(j != gridColSize[0] - 1 && grid[i][j + 1] == 1){grid[i]  [j+1] = t+1; new_good--;}
                }
        t++;//坏橘子代号增一
        if(new_good == good) return -1;//没有新的橘子变坏
        good = new_good;//还剩的好橘子
    }
    return q;
}
```