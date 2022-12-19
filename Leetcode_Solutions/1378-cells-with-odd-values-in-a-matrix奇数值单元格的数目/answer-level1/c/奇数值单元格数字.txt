### 解题思路
暴力循环，注意行列不要颠倒

### 代码

```c
int oddCells(int n, int m, int** indices, int indicesSize, int* indicesColSize){
    
    int **nums=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;++i)
    {
        nums[i]=(int*)malloc(sizeof(int)*m); 
        for(int j=0;j<m;++j)
            nums[i][j]=0;       
    }
    for(int i=0;i<indicesSize;++i)
    {
        int row=indices[i][0];
        for(int j=0;j<m;++j)
            nums[row][j]+=1;
        int col=indices[i][1];
        for(int j=0;j<n;++j)
            nums[j][col]+=1;
    }
    int sum=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(nums[i][j]%2)
                ++sum;

    for(int i=0;i<n;++i)
        free(nums[i]);
    free(nums);
    return sum;
}
```