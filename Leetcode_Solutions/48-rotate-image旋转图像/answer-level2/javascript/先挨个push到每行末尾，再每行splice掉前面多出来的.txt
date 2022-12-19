### 解题思路
![image.png](https://pic.leetcode-cn.com/bdd994839718dde361fe7db0695b7fe3e010e66f66676d938d4700e024e2ad9b-image.png)

不知道这样算不算“在原来的矩阵上修改”。

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    const len = matrix.length;
    let tmp = 0;

    for (let i = len - 1; i >= 0; i--) {
        for (let j = 0; j < len; j++) {
            matrix[j].push(matrix[i][j]);
        }
    }
    for (let i = 0; i < len; i++) {
        matrix[i].splice(0, len);
    }
};
```