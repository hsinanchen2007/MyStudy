思路：
- 矩阵的得分就是每一列的 1 的数量 * 2 的列数次方
- 第一列必须为 1
- 遍历行，如果第一个元素不为1，就翻转：可以通过 `A[r][c] ^ A[r][0]` 来实现
- 然后从第二列开始，统计 1 的数量，如果 1 的数量小于 0 的数量就翻转

```js
/**
 * @param {number[][]} A
 * @return {number}
 */
var matrixScore = function(A) {
  const rowLength = A.length;
  const colLength = A[0].length;
  // 第一列必须都为 1 直接计算出结果
  let result = rowLength * (1 << (colLength - 1));

  // 从第二列进行遍历统计当前列 1 的数量
  for (let colIndex = 1; colIndex < colLength; colIndex++) {
    let colCount = 0;
    for (let rowIndex = 0; rowIndex < rowLength; rowIndex++) {
      // 要保证第一列必须都为 1，就需要遍历行，通过异或运算实现:
      // 行首为 1 不翻转，为 0 就翻转
      colCount += A[rowIndex][colIndex] ^ A[rowIndex][0];
    }
    // 如果 1 的数量小于 0 的数量就翻转，尽可能的让当前列的 1 的数量最多
    const maxCount = Math.max(colCount, rowLength - colCount);
    // 计算当前列的结果
    result += maxCount * (1 << (colLength - 1 - colIndex));
  }

  return result;
};
```