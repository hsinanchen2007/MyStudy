### 解题思路
二分查找的二阶形式。

分析题意，该 M*N 的矩阵是递增的。
我们首先找出 target 可能所在的行，再在该行进行二分查找。

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
const searchRows = (matrix, target) => {
    let left = 0, right = matrix.length - 1;
    if (!matrix.length || !matrix[left].length) return left;
    while (left < right) {
        const mid = Math.floor((left + right) / 2);
        if (matrix[mid][0] === target) {
            return mid;
        }
        if (matrix[mid][0] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return matrix[left][0] > target ? Math.max(left - 1, 0) : left;
}

const searchColumns = (matrix, rowIndex, target) => {
    if (!matrix.length || !matrix[rowIndex].length) {
        return false;
    }
    let left = 0, right = matrix[rowIndex].length - 1;
    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        if (matrix[rowIndex][mid] === target) return true;
        if (matrix[rowIndex][mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return matrix[rowIndex][left] === target;
}

var searchMatrix = function(matrix, target) {
    return searchColumns(matrix, searchRows(matrix, target), target);
};
```

### 复杂度
- 时间复杂度 O((logM)*(logN))
- 空间复杂度 O(1)