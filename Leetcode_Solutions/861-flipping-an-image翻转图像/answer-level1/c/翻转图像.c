### 解题思路
水平翻转靠 low high
图像翻转靠 与1异或

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
    *returnSize=ASize;
    *returnColumnSizes=AColSize;
    for(int row=0;row<ASize;++row)
    {
        int low=0,high=AColSize[row]-1;
        while(low<high)
        {
            int temp=A[row][low];
            A[row][low]=A[row][high];
            A[row][high]=temp;
            A[row][low]=A[row][low]^1;
            A[row][high]=A[row][high]^1;
            ++low;--high;
        }
        if(low==high)
            A[row][low]=A[row][low]^1;
    }
    return A;
}
```