### 解题思路
常规解法，但是对于*returnSize开始时没有判断，导致一直出错

### 代码
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
       if(matrixSize == 0){
        *returnSize = NULL;
        return NULL;
        }
    int row = matrixSize;
    int col = matrixColSize[0];
   
    *returnSize = row * col;
    int *returnMatrix = malloc(*returnSize * sizeof(int));
    int up = 0;
    int down = row - 1;
    int left = 0;
    int right = col - 1;
    int index = 0;
    while(up <= down && left <= right){
        for(int i = left; i <= right; i++){
            returnMatrix[index++] = matrix[up][i];
        }
        if(++up > down){
            break;
        }
        for(int i = up; i <= down; i++){
            returnMatrix[index++] = matrix[i][right];
        }
        if(--right < left){
            break;
        }
        for(int i = right; i >= left; i--){
            returnMatrix[index++] = matrix[down][i];
        }
        if(--down < up){
            break;
        }
        for(int i = down; i >= up; i--){
            returnMatrix[index++] = matrix[i][left];
        }
        if(++left > right){
            break;
        }
    }
    return returnMatrix;
}
```
```c
