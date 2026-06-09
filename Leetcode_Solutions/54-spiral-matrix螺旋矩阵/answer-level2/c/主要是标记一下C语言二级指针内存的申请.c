```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 // 0向右 1向下 2向左 3向上
 int count = 0;
void func(int x, int y, int direction, int allnum, int * res, int ** flag, int length, int depth, int** matrix)
{

    if(count == allnum)
        return;
    if ((direction % 4) == 0) {
        if((flag[x][y] != 1) && ((y + 1) <= length)) {
            for (; (y < length) && (flag[x][y] != 1); y++) {
                res[count] = matrix[x][y];
                flag[x][y] = 1;
                count++;
            }
            func(x+1, y-1, direction+1, allnum, res, flag, length, depth, matrix);
        }
    }
    if ((direction % 4) == 1) {
        if((flag[x][y] != 1) && ((x + 1) <= depth)) {
            for (; (x < depth) && (flag[x][y] != 1); x++) {
                res[count] = matrix[x][y];
                flag[x][y] = 1;
                count++;
            }
            func(x - 1, y-1, direction+1, allnum, res, flag, length, depth, matrix);
        }
    }
    if ((direction % 4) == 2) {
        if((flag[x][y] != 1) && (y >= 0)) {
            for (; (y >= 0) && (flag[x][y] != 1); y--) {
                res[count] = matrix[x][y];
                flag[x][y] = 1;
                count++;
            }
            func(x - 1, y+1, direction+1, allnum, res, flag, length, depth, matrix);
        }
    }
    if ((direction % 4) == 3) {
        if((flag[x][y] != 1) && (x >= 0)) {
            for (; (x >= 0) && (flag[x][y] != 1); x--) {
                res[count] = matrix[x][y];
                flag[x][y] = 1;
                count++;
            }
            func(x + 1, y+1, direction+1, allnum, res, flag, length, depth, matrix);
        }
    }
}

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    int i;
    
    int *res = (int *)malloc(sizeof(int) * 10001);
    if (matrixSize == 0) {
        *returnSize = 0;
        return res;
    }
    int **flag = NULL;
    flag = (int **)malloc(sizeof(int *) * matrixSize);
    for(i = 0; i < matrixSize; i++) {
        flag[i] = (int *)malloc(sizeof(int) * (matrixColSize[0] + 1));
    }
    for(i = 0; i < matrixSize; i++) {
        memset(flag[i], 0, matrixColSize[0]);
    }
    count = 0;
    int allNum = matrixSize * matrixColSize[0];
    func(0,0,0,allNum,res, flag, matrixColSize[0], matrixSize,matrix);

    for(i = 0; i < matrixSize; i++) {
        free(flag[i]);
    }
    *returnSize = count;
    return res;
}
```
