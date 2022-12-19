### 解题思路
此处撰写解题思路

### 代码

```c
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if (matrix == NULL || matrixColSize == NULL) {
        return false;
    }
    if (matrixSize == 0 || *matrixColSize == 0) {
        return false;
    }
    if (matrix[0][0] > target) {
        return false;
    }
    if (matrix[matrixSize - 1][*matrixColSize - 1] < target) {
        return false;
    }
    int left = 0;   //left
    int right = matrixSize * (*matrixColSize) - 1;   //right
    while (left <= right) {
        int mid = left + (right - left) / 2;     //mid
        int x = mid / (*matrixColSize);
        int y = mid - (*matrixColSize) * x;      //再去找坐标点
        if (matrix[x][y] == target) {
            return true;
        } else if (matrix[x][y] < target) {
            left = mid + 1;
        } else {
            right = mid -1;
        }
    }
    return false;

}

```