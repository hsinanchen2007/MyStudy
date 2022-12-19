### 解题思路
1、利用杨氏矩阵，类似二分（对角二分法）
2、杨氏矩阵自行百度

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 * 利用杨氏矩阵算法
 * 纯逻辑写法
 */
function findNumber(matrix, target, max_y, min_x) {
    if(target > matrix[min_x][max_y]) {
        min_x++
        return min_x < matrix.length ? findNumber(matrix, target, max_y, min_x) : false
    }
    if(target < matrix[min_x][max_y]) {
        max_y--
        return max_y >= 0 ? findNumber(matrix, target, max_y, min_x) : false
    }
    return true
}
var findNumberIn2DArray = function(matrix, target) {
    if (matrix.length === 0) {
        return false
    }else if (matrix[0].length === 0) {
        return false
    }
    return Boolean(findNumber(matrix, target, matrix[0].length - 1, 0))
};

/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 * 利用数组拉平函数flat,再利用includes方法
 * 利用函数方法型
 */
function findNumber_second(matrix, target) {
    return matrix.flat(1).includes(target)
}
```