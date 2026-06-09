### 解题思路
因为忘记在差错处理返回NULL前忘记给入参赋值：*returnSize = 0;
就报错runtime error: load of null pointer of type 'int'
花费了20多分钟才发现。。。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void spiralOrderCore(int **matrix,int row,int col,int start,
                        int *arr,int *arr_index) {
    int endx = col - start - 1;
    int endy = row - start - 1;
    int i = 0;
    if (endx >= start) {
        for (i = start;i <= endx;++i) {
            *(arr + *arr_index) = matrix[start][i];
            ++(*arr_index);
        }
    }

    if (endy > start) {
        for (i = start + 1;i <= endy;++i) {
            *(arr + *arr_index) = matrix[i][endx];
            ++(*arr_index);
        }
    }

    if (endx > start && endy >start) {
        for (i = endx - 1;i >= start;--i) {
            *(arr + *arr_index) = matrix[endy][i];
            ++(*arr_index);
        }
    }

    if (endx > start && endy - start > 1) {
        for (i = endy - 1;i > start;--i) {
            *(arr + *arr_index) = matrix[i][start];
            ++(*arr_index);
        }
    }
 }

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int *return_arr = NULL;
    *returnSize = 0;
    if (matrixSize == 0 || matrixColSize == NULL || *matrixColSize == 0 || matrix == NULL || *matrix == NULL) 
        return return_arr;
    int row = matrixSize;
    int col = *matrixColSize;
    *returnSize = row * col;
    return_arr = (int*)calloc(*returnSize + 1,sizeof(int));

    // //row 行col 列的矩阵等待着被顺时针遍历
    int start = 0;
    int return_arr_counts = 0;

    while (row > start * 2 && col > start * 2) {
        spiralOrderCore(matrix,row,col,start,return_arr,&return_arr_counts);
        ++start;    
    }

    return return_arr;
}
```