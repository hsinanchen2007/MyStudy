```
//判断数字是否为1~9，且不能有重复，使用一个int A[10]数组记录出现次数，大于1或者等于0则不满足
bool Full(int **grid,int i,int j)
{
    int A[10]={0};
    for(int m=i;m-i<3;m++)
    {
        for(int n=j;n-j<3;n++)
        {
            if(grid[m][n]<1||grid[m][n]>9)
                return false;
            int k=grid[m][n];
            A[k]++;
        }
    }
    for(int k=1;k<10;k++)
    {
        if(A[k]>1||A[k]==0)
            return false;
    }
    return true;
}

//判断行列以及对角线是否相等
bool Add(int **grid,int i,int j)
{
    int n1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
    int n2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
    int n3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
    int n4 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
    int n5 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
    int n6 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];
    int n7 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
    int n8 = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];
    if(n1 == n2 && n2 == n3 && n3 == n4 && n4 == n5 && n5 == n6 && n6 == n7 && n7 == n8)
         return true;
    else
         return false;
    
}

//判断是否为幻方
bool check(int **grid,int i,int j)
{
     if(grid[i+1][j+1]!=5)  //幻方中间数必须是5，此条件不满足则无需进行下一步判断
         return false;
     if(!Full(grid,i,j))
         return false;
     if(!Add(grid,i,j))
         return false;
     return true;
}

int numMagicSquaresInside(int** grid, int gridSize, int* gridColSize){
    if(gridSize<3||*gridColSize<3)
         return 0; //行数列数必须都大于3
    int count=0;
    for(int i=0;i<gridSize-2;i++)
    {
        for(int j=0;j<*gridColSize-2;j++)
        {
            if(check(grid,i,j))
                count++;
        }
    }
    return count;
}


```