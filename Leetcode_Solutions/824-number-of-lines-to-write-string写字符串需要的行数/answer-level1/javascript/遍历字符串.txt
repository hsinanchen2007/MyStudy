```js
/**
 * @param {number[]} widths
 * @param {string} S
 * @return {number[]}
 */
var numberOfLines = function(widths, S) {
  let idx = 0;
  let rowSize = 0;
  let deep = 1;
  const cache = {};
  const len = S.length;
  const baseCode = String('a').charCodeAt();
  const getWidIdx = (char) => char.charCodeAt() - baseCode;
  while (idx < len) {
    const char = S[idx];
    const size = widths[getWidIdx(char)];
    rowSize += size;
    if (rowSize === 100) {
      deep += 1;
      rowSize = 0;
    } else if (rowSize > 100) {
      deep += 1;
      rowSize = size;
    }
    idx += 1;
  }
  return [deep, rowSize];
};
```
>执行用时 : 64 ms, 在所有 JavaScript 提交中击败了100.00%的用户
>内存消耗 : 34.4 MB, 在所有 JavaScript 提交中击败了92.31%的用户