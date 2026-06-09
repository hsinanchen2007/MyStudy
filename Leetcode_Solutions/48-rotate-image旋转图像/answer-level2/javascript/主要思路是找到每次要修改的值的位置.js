主要规律实际上是(x, y) -> (j, n - i - 1) 的循环替换，循环 4次;
实现方法为双层循环，最外层循环的次数为 floor(n / 2)，第二层起始点为外层的值，终止条件为 大于等于(n - i -1)

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
  let len = matrix.length;
  for (let i = 0; i < (len / 2 | 0); i++) {
    for (let j = i; j < len - 1 - i; j++) {
      let count = 0;
      let x = i, y = j;
      let t1 = matrix[x][y];
      while(count++ < 4) {
        let t = x;
        x = y;
        y = len - 1 - t;
        let t2 = matrix[x][y];
        matrix[x][y] = t1;
        t1 = t2;
      }
    }
  }
};
```