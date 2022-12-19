```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = matrixSize * (*matrixColSize);
    int *ret = (int *)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    int j = 0;
    int k = 0;
    while (k < (*returnSize)) {
        //printf("i , j %d,%d", i, j);
        ret[k] = matrix[i][j];
        if ((i + j) % 2 == 0) {/*偶数向上*/
            if (i > 0 && j < (*matrixColSize) - 1) {/*内部*/
                i--;
                j++;
            }else if (j < (*matrixColSize) - 1) {/*上边界*/
                j++;
            }else if (i >= 0) {/*右边界*/
                i++;
            }
        }else {/*奇数向下*/
            if (i < matrixSize -1 && j > 0) { /*内部*/
                i++;
                j--;
            }else if (i < matrixSize -1) {/*左边界*/
                i++;
            }else if (j >= 0) {/*下边界*/
                j++;
            }
        }
        k++;
    }
    return ret;
}
```
