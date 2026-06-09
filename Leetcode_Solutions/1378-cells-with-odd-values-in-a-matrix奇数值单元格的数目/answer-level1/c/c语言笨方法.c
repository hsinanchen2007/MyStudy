### 解题思路
这个思路是非常简洁明了的。

### 代码

```c
int oddCells(int n, int m, int** indices, int indicesSize, int* indicesColSize){
    int num[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            num[i][j]=0;
        }
    }
    int cnt=0;
    for(int i=0;i<indicesSize;i++)
    {
        for(int k=0;k<m;k++)
        {
            num[indices[i][0]][k]+=1;
        }
    }
    for(int i=0;i<indicesSize;i++)
    {
        for(int j=0;j<n;j++)
        {
            num[j][indices[i][1]]+=1;
        }
        
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d\n",num[i][j]);
            if(num[i][j]%2!=0)
            cnt++;
        }
    }
    *indicesColSize=n;
    return cnt;
}
```