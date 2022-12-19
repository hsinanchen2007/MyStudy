### 解题思路

 * 在研究x,y的坐标变化时，无意中发现可以通过在原数组上，经过两次反转得到
 * 先对角线反转，再中线左右反转即可
 * 可以哪一张正方形的纸，反转两下试一试
 * 时间复杂度 O(n^2) 空间复杂度O(1)

### 代码

```javascript
/**
 * 在研究x,y的坐标变化时，发现可以通过在原数组，对角线反转，在中线左右反转即可
 * 时间复杂度 O(n^2) 空间复杂度O(1)
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    const n = matrix.length;
    //对角线反转 0,0  n-1,n-1
    for(let i = 0; i < n; i++) {
        for(let j = 0; j < i; j++) {
            swap(matrix, [i, j], [j, i]);
        }
    }

    //中线左右反转
    for(let i = 0; i < n; i++) {
        for(let j = 0; j < n / 2; j++) {
            swap(matrix, [i, j], [i, n - 1 - j]);
        }
    }

    function swap(matrix, [x1, y1], [x2, y2]) {
        const tmp = matrix[x1][y1];
        matrix[x1][y1] = matrix[x2][y2];
        matrix[x2][y2] = tmp;
    }
};
```