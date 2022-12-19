### 解题思路
动态规划的题，看看官方题解，记一记就好了，不要自己乱分析。加强学习。

### 代码

```c
int del(int**G,int Size,int ColsSize)
{
    int result=G[Size-1][ColsSize-1];
    for(int i=0;i<Size;++i)
        free(G[i]);
    free(G);
    return result;
}
int minDistance(char * word1, char * word2){
    int rowNum_1=0,colNum_2=0;
    for(int i=0;word1[i]!='\0';++i)++rowNum_1;
    for(int i=0;word2[i]!='\0';++i)++colNum_2;

    int** grid=(int**)malloc(sizeof(int*)*(rowNum_1+1));
    for(int i=0;i<=rowNum_1;++i)
        grid[i]=(int*)malloc(sizeof(int)*(colNum_2+1));
    for(int i=0;i<=rowNum_1;++i)grid[i][0]=i;
    for(int i=0;i<=colNum_2;++i)grid[0][i]=i;

    for(int i=1;i<=rowNum_1;++i)
        for(int j=1;j<=colNum_2;++j)
            {
                int up = grid[i - 1][j] + 1;
                int left = grid[i][j - 1] + 1;
                int left_up =word1[i - 1] != word2[j - 1]? grid[i-1][j-1]+1 : grid[i - 1][j - 1];
                int min=up<left?up:left;
                grid[i][j]=min<left_up?min:left_up;
            }
    
    return del(grid,rowNum_1+1,colNum_2+1);
}
```