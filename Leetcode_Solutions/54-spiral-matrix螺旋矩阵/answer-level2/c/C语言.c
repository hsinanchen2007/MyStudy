int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){

    if(matrixSize==0){
        
        *returnSize=0;            //因为少了这几行代码，一直在leetcode上编译不过去！
        return 0;
    }
    int row = matrixSize;
    int col = *matrixColSize;
    *returnSize = row * col;
    int *result = calloc(matrixSize*col, sizeof(int));
    
    int index = 0;
    int r1 = 0, c1 = 0;
    int r2 = row - 1;
    int c2 = col - 1;
    while (r1 <= r2 && c1 <= c2){

        for (int c = c1; c <= c2; c++) {            //从左上角到右上角

            result[index++] = matrix[r1][c];
        }
        for (int r = r1 + 1; r <= r2; r++) {        //从右上角到右下角

            result[index++] = matrix[r][c2];
        }
        if (r1 < r2 && c1 < c2){    //若相等的话就表明在矩阵的中心了
            for (int c = c2 - 1; c > c1; c--) {        //从右下角到左下角

                result[index++] = matrix[r2][c];
            }
            for (int r = r2; r > r1; r--) {            //从左下角到左上角

                result[index++] = matrix[r][c1];
            }
        }
        r1++;
        r2--;            //这几行真是太妙了 每转一圈，就让原本的矩阵维度减一，也就是让矩阵的边界缩小
                         //转完一圈，就要开始装第二圈，所以起始位置就要加一
                         //若两个值相等的时候，就说明已经到矩阵的中心了
        c1++;
        c2--;            //所以这里的作用就是更新边界的条件和转圈的起始位置
    }
    return result;
}