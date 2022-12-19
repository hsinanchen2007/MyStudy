```js
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix: number[][]) {
  const len = matrix.length;
  let loopTimes = 0;

  function loopSwap(i: number, j: number, value: number): void {
    if (loopTimes === 4) {
      loopTimes = 0;
      return;
    }
    loopTimes++;
    let temp: number = matrix[j][len - 1 - i];
    matrix[j][len - 1 - i] = value;
    loopSwap(j, len - 1 - i, temp);
  }

  for (let i = 0; i < Math.floor(len / 2); i++) {
    for (let j = i; j < len - 1 - i; j++) {
      loopSwap(i, j, matrix[i][j]);
    }
  }
};
const a = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
];
rotate(a);
console.log(JSON.stringify(a));
```
