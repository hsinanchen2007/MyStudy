```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = matrixSize * (*matrixColSize);

    int* ans = (int*)malloc((*returnSize) * sizeof(int)); // 保存结果
    int p = -1;

    int visited[*returnSize]; // 未访问过的位置为0，否则为1，使用row * (*matrixColSize) + col为索引，row为纵坐标，col为横坐标
    memset(visited, 0, (*returnSize) * sizeof(int)); // 将数组中的值全部置为0

    int row = 0, col = 0;

    ans[++p] = matrix[0][0];
    visited[0] = 1;

    while (1) {
        int x[4] = {0, 1, 0, -1}, y[4] = {1, 0, -1, 0}; // x和y控制坐标移动的方向
        for (int i = 0; i < 4; ++i) {
            while (1) {

                if (p == *returnSize - 1 || 
                    (col + y[i]) == *matrixColSize || 
                    (row + x[i]) == matrixSize || 
                    (col + y[i]) < 0 || 
                    visited[(row + x[i]) * (*matrixColSize) + (col + y[i])] == 1) break;

                row += x[i];
                col += y[i];
                ans[++p] = matrix[row][col];
                visited[row * (*matrixColSize) + col] = 1;
            }
        }
        if (p == *returnSize - 1) break;
    }
    return ans;
}
```
