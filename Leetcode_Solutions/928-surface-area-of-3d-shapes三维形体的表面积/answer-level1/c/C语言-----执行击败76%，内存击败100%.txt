### 解题思路
此处撰写解题思路

### 代码

```c
int Compare(int x,int y){  //返回最小值
    if(x>y)
    return y;
    return x;
}
int Search(int**grid,int i,int j,int gridSize) //左下搜索
{
    int count=0;
    if(grid[i][j]>1)
    count=count+grid[i][j]-1;
    if(j+1<gridSize)
    count+=Compare(grid[i][j],grid[i][j+1]);
    if(i+1<gridSize)
    count+=Compare(grid[i][j],grid[i+1][j]);
    return count;
}

int surfaceArea(int** grid, int gridSize, int* gridColSize){
int i,j,sum=0,count=0;
for(i=0;i<gridSize;i++){
    for(j=0;j<gridSize;j++){
        sum+=grid[i][j];
        count+=Search(grid,i,j,gridSize);
    }
}
return sum*6-count*2;
}
```