### 解题思路
先用toString将矩阵转化为字符串 "1,4,7,11,15,2,5,8,12,19,3,6,9,16,22,10,13,14,17,24,18,21,23,26,30"
然后用split分隔为一维数组
然后使用includes查找target

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function (matrix, target) {
    return matrix.toString().split(',').includes(target.toString())
};

```