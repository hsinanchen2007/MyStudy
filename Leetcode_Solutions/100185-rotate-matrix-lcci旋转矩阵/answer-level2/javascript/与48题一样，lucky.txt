### 解题思路
![image.png](https://pic.leetcode-cn.com/486ce1f8cc38b049740a90fabe4644d588b763211e213055cac248bec5973d7c-image.png)

先挨个push到每行末尾，再每行splice掉前面多出来的，不知道这样算不算“在原来的矩阵上修改”。

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    const len = matrix.length;

    for (let i = len - 1; i >= 0; i--) {
        for (let j = 0; j < len; j++) {
            matrix[j].push(matrix[i][j]);
        }
    }
    for (let i = 0; i < len; i++) {
        matrix[i].splice(0, len);
    }
    // console.log(matrix);
};
```