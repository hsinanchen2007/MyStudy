```
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    char p = 0;
    for (int i = 0;i < matrixSize;i++) {
        for (int j = 0; j < matrixColSize[0];j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;   //将需要置零的行号 在第一列上打一个标记，标为0
                matrix[0][j] = 0;   //将需要置零的列号 在第一行上打一个标记，标为0
                //对于本身就处于首行 首列的特殊处理。
                if (i == 0) { 
                    p |= 1 << 0; //第一行全为0；
                }
                if (j == 0) {
                    p |= 1 << 1; //第一列全为0；
                }
            }
        }
    }
    /*根据第一列的标记，刷新行*/
    for (int i = 1;i < matrixSize;i++) {
        if (matrix[i][0] == 0) {
            for (int j = 1;j < matrixColSize[0];j++) {
                matrix[i][j] = 0;
            }
        }
    }
    /*根据第一行的标记，刷新列*/
    for (int j = 1;j < matrixColSize[0];j++) {
        if (matrix[0][j] == 0) {
            for (int i = 1;i < matrixSize;i++) {
                matrix[i][j] = 0;
            }
        }
    }
    /*处理首行首列*/
    if (p & 0x01) {
        for (int j = 0;j < matrixColSize[0];j++) {
            matrix[0][j] = 0;
        }
    }
    if (p & 0x02) {
        for (int i = 0;i < matrixSize;i++) {
            matrix[i][0] = 0;
        }
    }

}      
```
