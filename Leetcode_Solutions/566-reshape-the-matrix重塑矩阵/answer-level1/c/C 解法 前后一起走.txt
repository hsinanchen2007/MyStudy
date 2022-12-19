# **代码：**
```

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsSize, int* numsColSize, int r, int c, int* returnSize, int** returnColumnSizes){
    if(numsSize*numsColSize[0] != r*c){
        *returnSize = numsSize;
        *returnColumnSizes = numsColSize;
        return nums;
    }

    int **returnarr = malloc(sizeof(int*) * r),
        *returncolumns = malloc(sizeof(int) * r),
        *eachrow,sum = 0,row = 0,col = 0,end,i;

    for(i = 0;i < r;i++){
        eachrow = malloc(sizeof(int)* c);
        returnarr[i] = eachrow;
        returncolumns[i] = c;
    }
    
    while(numsSize - row - 1>= row){
        end = r*c-1 - sum;
        returnarr[sum/c][sum%c] = nums[row][col];
        returnarr[end/c][end%c] = nums[numsSize - row - 1][*numsColSize - col - 1];
        sum++;
        row = sum/ *numsColSize;
        col = sum% *numsColSize;
    }
    *returnSize = r;
    *returnColumnSizes = returncolumns;
    return returnarr;
}

```
