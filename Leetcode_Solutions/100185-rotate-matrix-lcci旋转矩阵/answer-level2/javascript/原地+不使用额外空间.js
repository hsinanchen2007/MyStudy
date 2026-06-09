### 解题思路
![image.png](https://pic.leetcode-cn.com/2c9e70bd6502604e2976ab936720542849f9b2509990f01d042f3fc9f6605cf0-image.png)

1. 将元素按照旋转的方向一个个push到队尾
2. 截取掉前面的旧元素

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    if (!matrix || !matrix.length) return;
    if (matrix.length === 1) return matrix;
    let len = matrix.length;
    for (let i = len - 1; i >= 0; i--) {
        for (let j = 0; j < len; j++) {
            matrix[j].push(matrix[i][j]);
        }
    }
    matrix.forEach(item => item.splice(0, len));
};
```