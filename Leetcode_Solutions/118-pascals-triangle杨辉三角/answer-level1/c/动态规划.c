### 解题思路
dp[i][j] = dp[i-1][j-1] + dp[i-1][j];

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows;
    int ** dp = malloc(sizeof(int *)*numRows);
    (*returnColumnSizes) = malloc(sizeof(int)*numRows);
    if(numRows == 0) return dp;
    for(int i = 0; i < numRows; i++){
        dp[i] = malloc(sizeof(int)*(i+1));
        dp[i][0] = 1;
        dp[i][i] = 1;
        (*returnColumnSizes)[i] = i+1;
    }

    for(int i = 1; i <numRows; i++){
        for(int j = 1; j < (*returnColumnSizes)[i] - 1; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    } 
    return dp;
}
```