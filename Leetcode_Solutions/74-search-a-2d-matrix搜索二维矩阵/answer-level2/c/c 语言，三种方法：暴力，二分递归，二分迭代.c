解法1：暴力解
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (target == matrix[i][j]) {
                return true;
            }
        }
    }
    return false;
}

解法2： 二分法，递归
bool binRecursive(int **matrix, int *matrixColSize, int left, int right, int target)
{
    if (left > right) {
        return false;
    }
    int mid = left + (right - left) / 2;
    int row = mid / *matrixColSize;
    int col = mid % *matrixColSize;
    
    if (matrix[row][col] == target) {
        return true;
    } else if (matrix[row][col] < target) {
        return binRecursive(matrix, matrixColSize, mid + 1, right, target);
    } else {
        return binRecursive(matrix, matrixColSize, left, mid - 1, target);
    }
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int left = 0;
    int right = matrixSize * (*matrixColSize) - 1;
    
    if (matrixSize == 0 || *matrixColSize == 0) {
        return false;
    }

    return binRecursive(matrix, matrixColSize, left, right, target);
}

解法3： 二分法，迭代
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int left = 0;
    int right = matrixSize * (*matrixColSize) - 1;
    int mid;
    int row;
    int col;

    if (matrixSize == 0 || *matrixColSize == 0) {
        return false;
    }

    while (left <= right) {
        mid = left + (right - left) / 2;
        row = mid / (*matrixColSize);
        col = mid % (*matrixColSize);

        if (target == matrix[row][col]) {
            return true;
        } else if (target < matrix[row][col]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}



