```
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize=numRows;
    *returnColumnSizes=(int*)malloc(numRows * sizeof(int));
    int **res=(int**)malloc((*returnSize) * sizeof(int*));
    int i,j;
    int left=0,right=0;
    if(numRows==0)
        return res;
    (*returnColumnSizes)[0]=1;
    res[0]=(int*)malloc((*returnColumnSizes)[0] * sizeof(int));
    res[0][0]=1;
    for(i=1;i<numRows;i++)
    {
        (*returnColumnSizes)[i]=i+1;
        res[i]=(int*)malloc((*returnColumnSizes)[i] * sizeof(int));
        for(j=0;j<=i;j++)
        {
            if(j-1<0)
                left=0;
            else
                left=res[i-1][j-1];
            if(j>i-1)
                right=0;
            else
                right=res[i-1][j];
            res[i][j]=left+right;
        }
    }
    return res;
}
```
010
0120
01230
012340
0123450
可以想象成这样↑
res[i][j]=res[i-1][j-1]+res[i-1][j];
避免越界，直接将最左最右赋0