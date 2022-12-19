```
void UpdateMax(int *max, int sum)
{
    if (sum > *max) {
        *max = sum;
    }
}

int MaxRow(char** matrix, int row, int col, int max)
{
    int total = 0;

    for (int j = col; j < max; j++) {
        if (matrix[row][j] == '1') {
            total++;
        } else {
            break;
        }
    }
    return total;
}

int MaxCol(char** matrix, int row, int col, int max)
{
    int total = 0;

    for (int i = row; i < max; i++) {
        if (matrix[i][col] == '1') {
            total++;
        } else {
            break;
        }
    }
    return total;
}

bool CheckZero(char** matrix, int row, int col, int maxEdge)
{
    for (int i = row; i < row + maxEdge; i++) {
        for (int j = col; j < col + maxEdge; j++) {
            if (matrix[i][j] == '0') {
                return true;
            }
        }
    }
    return false;
}

bool CheckParam(char** matrix, int matrixSize, int* matrixColSize)
{
    if (matrixSize == 0) {
        return true;
    }
    return false;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize)
{
    int row = matrixSize;
    int col = 0;
    int maxRow = 0;
    int maxCol = 0;
    int maxEdge = 0;
    int sum = 0;
    int res = 0;

    if (CheckParam(matrix, matrixSize, matrixColSize)) {
        return 0;
    }
    col = *matrixColSize;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == '1') {
                maxRow = MaxRow(matrix, i, j, col);
                maxCol = MaxCol(matrix, i, j, row);
                maxEdge = fmin(maxRow, maxCol);
                while (CheckZero(matrix, i, j, maxEdge)) {
                    maxEdge--;
                }
                sum = maxEdge * maxEdge;
                UpdateMax(&res, sum);
            }
        }
    }
    return res;
}
```
