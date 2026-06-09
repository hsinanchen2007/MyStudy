### 解题思路
题目较简单，注意函数通过传入地址来提供多个返回值。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize=numRows;
    if(numRows==0){
        returnColumnSizes=NULL;
        return NULL;
    }
    *returnColumnSizes=(int*)malloc(sizeof(int)*numRows);
    for(int i=1;i<=numRows;i++)
        (*returnColumnSizes)[i-1]=i;

    int **generate,**tmp;
    generate=(int**)malloc(sizeof(int*)*numRows);
    tmp=generate;
    for(int i=0;i<numRows;i++){
        *tmp=(int*)malloc(sizeof(int)*(i+1));
        generate[i][0]=1;
        generate[i][i]=1;
        for(int j=1;j<i;j++)
            generate[i][j]=generate[i-1][j-1]+generate[i-1][j];
        tmp++;
    }
    return generate;
}
```