```
var surfaceArea = function(grid) {
  let s = 0;
  // 遍历每个位置的正方体
  for (let x = 0; x < grid.length; x++) {
    for (let y = 0; y < grid.length; y++) {
      // 计算单个位置的正方体表面积
      // 不管有多少个正方体纵向堆叠
      // 上下始终都只有各一面露出
      let currentCount = grid[x][y];
      if (currentCount > 0) {
        s = currentCount * 4 + 2 + s;
        // 每个位置再减去与之相邻的侧面面积
        // 每有一个侧面相互接触则总面积减去两个单位面积
        // 相互接触的个数等于两个接触体较短的那个
        if (x > 0) {
          let xSideCount = grid[x - 1][y];
          let xTouchCount =
            xSideCount < currentCount ? xSideCount : currentCount;
          s = s - 2 * xTouchCount;
        }
        // y轴方向同理
        if (y > 0) {
          let ySideCount = grid[x][y - 1];
          let yTouchCount =
            ySideCount < currentCount ? ySideCount : currentCount;
          s = s - 2 * yTouchCount;
        }
      }
    }
  }
  return s;
};
```
