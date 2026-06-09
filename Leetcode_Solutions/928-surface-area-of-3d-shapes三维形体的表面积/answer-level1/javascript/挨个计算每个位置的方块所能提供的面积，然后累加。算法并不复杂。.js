### 解题思路

计算每个位置能提供的面积，然后累加。

举例：
如果有，首先会提供顶部 和 底部两个。
剩下侧面的，与四周比较，比旁边的高多少，那个方向就能提供多少。

注意要判断如果在边缘时，获取周围的方块数小心空指针报错。

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
    // 分别计算每个位置贡献的表面积，然后进行累加
    let result = 0;
    const length = grid.length;
    for (let i = 0; i < length; i++) {
        for (let j = 0; j < length; j++) {
            if (grid[i][j] > 0) {
                result += 2;
                
                result += Math.max(grid[i][j] - (grid[i - 1] && grid[i - 1][j] || 0), 0);
                result += Math.max(grid[i][j] - (grid[i][j - 1] || 0), 0);
                result += Math.max(grid[i][j] - (grid[i + 1]&&grid[i + 1][j] || 0), 0);
                result += Math.max(grid[i][j] - (grid[i][j + 1] || 0), 0);
            }
        }
    }
    return result;
};
```