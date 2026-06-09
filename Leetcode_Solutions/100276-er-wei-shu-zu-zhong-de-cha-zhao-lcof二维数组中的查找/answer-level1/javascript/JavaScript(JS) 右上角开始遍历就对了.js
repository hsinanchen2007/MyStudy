### 解题思路
右上角开始遍历就对了，一次判断缩小一行(列)

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function (matrix, target) {
    if (!matrix.length) return false
    let row = matrix.length;
    let column = matrix[0].length - 1;
    let i = 0, j = column;

    while (i < row && j >= 0) {
        if (matrix[i][j] === target) {
            return true
        } else if (matrix[i][j] > target) {
            j--;
        } else {
            i++;
        }
    }
    return false
};
```
![搜索框传播样式-标准色版.png](https://pic.leetcode-cn.com/5b693dce2ea930fe7d095fbb126cc9e8b0d109de3e59c4f09c898d62a09d7a9b-%E6%90%9C%E7%B4%A2%E6%A1%86%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)
