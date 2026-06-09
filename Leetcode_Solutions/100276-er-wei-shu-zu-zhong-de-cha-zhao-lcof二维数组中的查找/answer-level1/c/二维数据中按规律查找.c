执行用时 :44 ms, 在所有 C 提交中击败了67.21的用户
内存消耗 :9.7 MB, 在所有 C 提交中击败了100.00%的用户

通过交叉点来每次排除左下方的矩形块数据，仅对该数据块上方的数据进行检索
```
bool findNumByCro(int** matrix, int matrixSize, int* matrixColSize, int cross, int target)
{
    if (cross == matrixSize || cross == *matrixColSize || matrix[cross][cross] > target) {
        return false;
    }
    
    if (matrix[cross][cross] == target) return true;
    
    if (findNumByCro(matrix, matrixSize, matrixColSize, cross + 1, target)) {
        return true;
    } else {
        for (int i = cross; i < matrixSize; i++) {
            if (matrix[i][cross] > target) break;
            if (matrix[i][cross] == target) return true;
        }
        
        for (int j = cross; j < *matrixColSize; j++) {
            if (matrix[cross][j] > target) break;
            if (matrix[cross][j] == target) return true;
        }
        return false;
    }
}

bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
    if (matrixSize == 0 || *matrixColSize == 0) {
        return false;
    }
    if (matrix[0][0] > target) {
        return false;
    }
    
    return findNumByCro(matrix, matrixSize, matrixColSize, 0, target);  
}
```
