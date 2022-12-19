解法一：二分法，迭代

bool binSearch(int **matrix, int matrixRowSize, int matrixColSize, int target, int start, bool vertical)
{
    int lo = start;
    int hi = vertical ? (matrixColSize - 1) : (matrixRowSize - 1);

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (vertical) {
            if (matrix[start][mid] == target) {
                return true;
            } else if (matrix[start][mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        } else {
            if (matrix[mid][start] == target) {
                return true;
            } else if (matrix[mid][start] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
    return false;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int shortDim =(matrixRowSize < matrixColSize ? matrixRowSize : matrixColSize);
    bool verticalFound;
    bool horizonFound;

    if (matrixRowSize == 0 || matrixColSize == 0) {
        return false;
    }
    for (int i = 0; i < shortDim; i++) {
        verticalFound = binSearch(matrix, matrixRowSize, matrixColSize, target, i, true);
        horizonFound = binSearch(matrix, matrixRowSize, matrixColSize, target, i, false);
        if (verticalFound || horizonFound) {
            return true;
        }
    }
    return false;
}

解法2：二分法，递归
bool binSearch(int **matrix, int target, int lo, int hi, int start, bool vertical)
{
    int mid = lo + (hi - lo) / 2;
    
    if (lo > hi) {
        return false;
    }
    if (vertical) {
        if (matrix[start][mid] == target) {
            return true;
        } else if (matrix[start][mid] < target) {
            return binSearch(matrix, target, mid + 1, hi, start, vertical);
        } else {
            return binSearch(matrix, target, lo, mid - 1, start, vertical);
        }
    } else {
        if (matrix[mid][start] == target) {
            return true;
        } else if (matrix[mid][start] < target) {
            return binSearch(matrix, target, mid + 1, hi, start, vertical);
        } else {
            return binSearch(matrix, target, lo, mid - 1, start, vertical);
        }
    }
    return false;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int shortDim =(matrixRowSize < matrixColSize ? matrixRowSize : matrixColSize);
    bool verticalFound;
    bool horizonFound;
    int hi, lo;
    if (matrixRowSize == 0 || matrixColSize == 0) {
        return false;
    }
    for (int i = 0; i < shortDim; i++) {
        lo = i;
        hi = (matrixColSize - 1);
        verticalFound = binSearch(matrix, target, lo, hi, i, true);
        hi = (matrixRowSize - 1);
        horizonFound = binSearch(matrix, target, lo, hi, i, false);
        if (verticalFound || horizonFound) {
            return true;
        }
    }
    return false;
}