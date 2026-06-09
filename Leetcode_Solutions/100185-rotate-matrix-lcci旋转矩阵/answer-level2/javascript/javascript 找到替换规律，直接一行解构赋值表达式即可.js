本题考察知识点：
  - 二维数组的基本操作及遍历的编码功底

本题收获：
  - 应该要熟练编写二维数组的行列互换，顺逆翻转，合并等操作的代码
  - 熟练用数组进行原地空间操作


```javascript
/**
 * 面试题 01.07. Rotate Matrix LCCI
 * https://leetcode-cn.com/problems/rotate-matrix-lcci/
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
/**
 * 方法一：模拟元素之间的两两交换，循环依次进行元素互换 时间复杂度：O(n^2) 空间复杂度：O(1)
 * matrix[j][n-i-1] = matrix[i][j]
 * matrix[n-i-1][n-j-1] = matrix[j][n-i-1]
 * matrix[n-j-1][i] = matrix[n-i-1][n-j-1]
 * matrix[i][j] = matrix[n-j-1][i]
 */
var rotate = function(matrix) {
  let n = matrix.length, len = n >> 1
  for (let i = 0; i < (len); i++) {
    for (let j = i; j < n-i-1; j++) {
      [ matrix[i][j], matrix[j][n-i-1], matrix[n-i-1][n-j-1], matrix[n-j-1][i] ] = [ matrix[n-j-1][i], matrix[i][j], matrix[j][n-i-1], matrix[n-i-1][n-j-1] ]
    }
  }
};

/**
 * 方法二：找规律，先沿水平轴翻转一次，再沿主对角线(捺)翻转一次，即完成了图像旋转90度的题意 时间复杂度：O(n^2) 空间复杂度: O(1)
 */
const rotate = (matrix) => {
  let n = matrix.length
  for (let i = 0; i < (n >> 1); i++) {
    for (let j = 0; j < n; j++) {
      [matrix[i][j], matrix[n-i-1][j]] = [matrix[n-i-1][j], matrix[i][j]]
    }
  }
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      [matrix[i][j], matrix[j][i]] = [matrix[j][i], matrix[i][j]]
    }
  }
}
```

[更多 Leetcode For Javascript 题解请关注](https://github.com/dwgeneral/JS-Leetcode)