### 解题思路
代码很清晰了，不懂的欢迎留言

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize=numRows;

    //for triangle
    int **matrix=(int **)malloc(sizeof(int *)*numRows);

    //for outpus
    int *outpus=(int *)malloc(sizeof(int)*numRows);

    int i,j;
    for(i=0;i<numRows;i++)
    {
        matrix[i]=(int *)malloc(sizeof(int)*(i+1));
        outpus[i]=i+1;//记录长度
        for(j=0;j<=i;j++)
        {
            if(j==0||j==i)//边界初始化
                matrix[i][j]=1;
            else
                matrix[i][j]=matrix[i-1][j-1]+matrix[i-1][j];//状态转移方程
        }
    }
    *returnColumnSizes=outpus;
    return matrix;
}
```