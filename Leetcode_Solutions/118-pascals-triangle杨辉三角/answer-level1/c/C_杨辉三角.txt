### 解题思路
特殊情况 输入0 1 2的时候
其他情况，看图解题

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    if(numRows==0)
    {
        *returnSize=0;
        *returnColumnSizes=0;
        return 0;
    }
    //返回的行数=指定的行数
    *returnSize=numRows;
    //每行的列数存放到一个数组里，每一行列数=行数
    *returnColumnSizes=(int*)malloc(sizeof(int)*numRows);
    for(int i=0;i<numRows;++i)
        (*returnColumnSizes)[i]=i+1;
    //返回的矩阵有指定的行数
    int** result=(int**)malloc(sizeof(int*)*numRows);
    //第一行第一列肯定是1
    result[0]=(int*)malloc(sizeof(int));
    result[0][0]=1;
    if(numRows==1) return result;
    //第二行两个元素都是1
    result[1]=(int*)malloc(sizeof(int)*2);
    result[1][0]=1;result[1][1]=1;
    if(numRows==2) return result;
    //从第三行开始初始化
    for(int row=2;row<numRows;++row)
    {
        result[row]=(int*)malloc(sizeof(int)*((*returnColumnSizes)[row]));
        result[row][0]=1;result[row][(*returnColumnSizes)[row]-1]=1;
        for(int i=1;i<(*returnColumnSizes)[row]-1;++i)
            result[row][i]=result[row-1][i]+result[row-1][i-1];
    }
    return result;
}
```