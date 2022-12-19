```
代码块
```
#define MAX_SIZE 150
int book[MAX_SIZE][MAX_SIZE] = {0};
int M = 0;
int N = 0;
int flag = 1;
int DSP(int** matrix, int i, int j) {
    if (book[i][j] >= flag) {
        return 0;
    }
    book[i][j] += flag;
    int direct[] = {-1, 0, 1, 0, -1};
    for (int k = 0; k < 4; k++) {
        int x = i + direct[k];
        int y = j + direct[k + 1];
        if (x < 0 || y < 0 || x > M -1 || y > N - 1 || matrix[x][y] < matrix[i][j]) {
            continue;
        }
        DSP(matrix, x, y);
    }
    return 0;
    
}
    
int** pacificAtlantic(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    M = matrixSize;
    if (M == 0) {
        *returnSize = 0;
        return NULL;
    }
    N = *matrixColSize; 
    returnColumnSizes[0] = (int*)malloc(MAX_SIZE * MAX_SIZE * sizeof(int));
    int **result = (int**)malloc(MAX_SIZE * MAX_SIZE * sizeof(int*));
    int count = 0;
    memset(book, 0, MAX_SIZE * MAX_SIZE * sizeof(int));
    flag = 1;
    for (int i = 0; i < matrixSize; i++) {
        DSP(matrix, i, 0);        
    }
    for (int i = 0; i < *matrixColSize; i++) {
        DSP(matrix, 0, i);        
    }
    flag = 10;
    for (int i = 0; i < matrixSize; i++) {
        DSP(matrix, i, *matrixColSize - 1);        
    }
    for (int i = 0; i < *matrixColSize; i++) {
        DSP(matrix, matrixSize - 1, i);        
    }
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            printf("book[%d][%d] = %d\n", i, j, book[i][j]);
            if (book[i][j] == 11) {
                result[count] = (int*)malloc(2 * sizeof(int));
                result[count][0] = i;
                result[count][1] = j;
                returnColumnSizes[0][count] = 2;
                count++;
            }      
        }     
    }
    *returnSize = count;
    return result;
}