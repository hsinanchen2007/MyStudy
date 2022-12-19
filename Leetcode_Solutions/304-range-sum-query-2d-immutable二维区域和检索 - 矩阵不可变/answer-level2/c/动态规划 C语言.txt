```
typedef struct {
    int matrixSize;
    int* matrixColSize;
    int** matrix; 
} NumMatrix;


NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    NumMatrix* obj=malloc(sizeof(NumMatrix));
    //printf("%p\n",obj);
    obj->matrixColSize = (int*)malloc(matrixSize*sizeof(int));
    //printf("%p\n",obj->matrixColSize);
    obj->matrix = (int**)malloc(matrixSize*sizeof(int*));
    for(int i=0;i<matrixSize;i++) {
        obj->matrixColSize[i] = matrixColSize[i];
        obj->matrix[i] = (int*)malloc(matrixColSize[i]*sizeof(int));
        //printf("%p\n",obj->matrix[i]);
        for(int j=0;j<matrixColSize[i];j++) {
            if(i==0 && j==0) {
                obj->matrix[i][j] = matrix[i][j];
            }
            else if(i==0) {
                obj->matrix[i][j] = obj->matrix[i][j-1] + matrix[i][j];
            }
            else if(j==0) {
                obj->matrix[i][j] = obj->matrix[i-1][j] + matrix[i][j];
            }
            else {
                obj->matrix[i][j] = obj->matrix[i-1][j] + obj->matrix[i][j-1] - obj->matrix[i-1][j-1] + matrix[i][j];
            }
        }
    }
    return obj;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    //printf("main %p ",obj);
    //printf("v1 %d\n", obj->matrix[row2][col2]);
    if(row1==0 && col1==0) {
        return obj->matrix[row2][col2];
    }
    if(row1==0) {
        return obj->matrix[row2][col2] - obj->matrix[row2][col1-1];
    } 
    if(col1==0) {
        return obj->matrix[row2][col2] - obj->matrix[row1-1][col2];
    }
    return obj->matrix[row2][col2]-obj->matrix[row2][col1-1]-obj->matrix[row1-1][col2]+obj->matrix[row1-1][col1-1];
}

void numMatrixFree(NumMatrix* obj) {
    for(int i=0;i<obj->matrixSize;i++) {
        free(obj->matrix[i]);
    }
    free(obj->matrix);
    free(obj->matrixColSize);
    free(obj); 
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 
 * numMatrixFree(obj);
*/
```
