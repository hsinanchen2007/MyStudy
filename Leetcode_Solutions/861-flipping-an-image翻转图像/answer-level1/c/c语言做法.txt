### 解题思路
使用了左右哨兵，然后位置互换。

### 代码

```c


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
    for(int i=0;i<ASize;i++)
    {
        int left=0,right=*AColSize-1;
        while(left<right)
        {
            int temp=A[i][left];
            A[i][left]=A[i][right];
            A[i][right]=temp;
            left++;
            right--;
        }
    }
    for(int i=0;i<ASize;i++)
    {
        for(int j=0;j<*AColSize;j++)
        {
            A[i][j]=abs(A[i][j]-1);
        }
    }
    *returnSize=ASize;
    *returnColumnSizes=AColSize;
    return A;
}


```