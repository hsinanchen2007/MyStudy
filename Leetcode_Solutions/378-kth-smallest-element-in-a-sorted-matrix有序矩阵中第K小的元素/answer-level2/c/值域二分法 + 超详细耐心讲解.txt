```
首先第k大数一定落在[l, r]中，其中l = matrix[0][0], r = matrix[row - 1][col - 1].
我们二分值域[l, r]区间，mid = (l + r) >> 1, 对于mid，我们检查矩阵中有多少元素小于等于mid，
记个数为cnt，那么有：

1、如果cnt < k, 那么[l, mid]中包含矩阵元素个数一定小于k，那么第k小元素一定不在[l, mid]
中，必定在[mid + 1, r]中，所以更新l = mid + 1.

2、否则cnt >= k，那么[l, mid]中包含矩阵元素个数就大于等于k，即第k小元素一定在[l,mid]区间中，
更新r = mid;

至于怎么得矩阵中有多少元素小于等于k，可以利用矩阵本身性质，从左下角开始按列枚举，具体可参考代码。

综上：
算法时间复杂度为O(n * log(m)), 其中n = max(row, col)，代表矩阵行数和列数的最大值,
 m代表二分区间的长度，即矩阵最大值和最小值的差。

int getLowerCnt(int **matrix, int row, int col, int mid)
{
    int i = row - 1, j = 0, cnt = 0;
    while (i >= 0 && j < col) {
        if (matrix[i][j] <= mid) {
            cnt = cnt + i + 1;
            j++;
        } else {
            i--;
        }
    }
    return cnt;
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
    if (matrix == NULL || matrixColSize == NULL || matrixSize == 0) return -1;
    int row = matrixSize, col = matrixColSize[0];
    int l = matrix[0][0], r = matrix[row - 1][col - 1];
    while (l < r) {
        int mid = (l + r) >> 1;
        if (getLowerCnt(matrix, row, col, mid) < k) { // 落在区间[l, mid]中数小于k，说明第k小的数一定大于mid
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
```
