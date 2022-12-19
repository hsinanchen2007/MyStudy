### 解题思路
核心部分在于开辟内存。
returnColumnSizes这个东西为什么设置成二维的一直搞不懂。有人可以解释一下吗？

### 代码

```c


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
    int** num=(int**)malloc(sizeof(int*)* *AColSize);
    *returnColumnSizes=(int*)malloc(sizeof(int)* *AColSize);
    *returnSize=*AColSize;
    for(int i=0;i<*AColSize;i++)
    {
        num[i]=(int*)malloc(sizeof(int)*ASize);
        (*returnColumnSizes)[i]=ASize;
    }
    for(int i=0;i<ASize;i++)
    {
        for(int j=0;j<*AColSize;j++)
        {
            num[j][i]=A[i][j];
        }
    }
    return num;
}


```