### 解题思路
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。




### 代码

```c
int gmatrixColSize;
int gmatrixRowSize;
bool binarySearch(int** matrix, int fix, int target, bool is_row) {
    int high, mid, low = fix;

    if (is_row)
        high = gmatrixColSize-1;
    else
        high = gmatrixRowSize-1;

    while (low <= high) {
        if (is_row) {
            mid = (low + high)/2;
            if (matrix[fix][mid] == target)
                return true;
            else if (matrix[fix][mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        } else {
            mid = (low + high)/2;
            if (matrix[mid][fix] == target)
                return true;
            else if (matrix[mid][fix] < target)
                low = mid + 1;
            else 
                high = mid - 1;
        }
    }
    return false;
}


bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int i = 0;
    int max = matrixRowSize < matrixColSize ? matrixRowSize : matrixColSize;
    bool row = false, col = false;

    gmatrixColSize = matrixColSize;
    gmatrixRowSize = matrixRowSize;
    for (i = 0; i < max; i++) {
        row = binarySearch(matrix, i, target, true);
        col = binarySearch(matrix, i, target, false);
        if (row || col)
            return true;
    }
    return false;
}
```