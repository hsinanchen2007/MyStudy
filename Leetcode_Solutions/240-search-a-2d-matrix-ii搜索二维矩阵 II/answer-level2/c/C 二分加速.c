### 解题思路
C二分加速 查找

### 代码

```c
bool searchVector(int *v,int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (v[mid] == target)
            return true;
        if (v[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
        }

    return false;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int m = matrixRowSize;
    int n = matrixColSize;
    if (m == 0 || n == 0) {
        return false;
    }
    for(int i=0 ; i<m ; ++i){
        if(matrix[i][0] <= target && matrix[i][n-1] >= target){
            if(searchVector(matrix[i], n, target))
                return true;
        }
    }
        return false;
}
```