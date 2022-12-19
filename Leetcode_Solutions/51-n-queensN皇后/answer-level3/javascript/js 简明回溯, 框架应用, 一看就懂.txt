```js
var solveNQueens = function(n) {
  // 列占位
  const columns = [];

  // 主对角线占位
  const main = [];

  // 次对角线占位
  const secondary = [];

  return dfs([]);

  function dfs(arr) {
    if (arr.length === n)
      return [
        arr.map(
          item =>
            new Array(item).fill(".").join("") +
            "Q" +
            new Array(n - item - 1).fill(".").join("")
        )
      ];

    let res = [];
    const row = arr.length - 1;

    for (let col = 0; col < n; col++) {
      if (isInvalid(row, col)) continue;

      toggleLimit(row, col, true);

      res = res.concat(dfs([...arr, col]));

      toggleLimit(row, col, false);
    }

    return res;
  }

  function isInvalid(row, col) {
    return columns[col] || main[row - col + n * 2] || secondary[row + col];
  }

  function toggleLimit(row, col, on = true) {
    columns[col] = on;

    main[row - col + n * 2] = on;

    secondary[row + col] = on;
  }
};
```