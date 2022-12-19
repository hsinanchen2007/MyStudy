### 解题思路

遍历 grid，找到值为 1 的元素，以此元素为起点向四周递归查找相邻的值为 1 的元素

### 复杂度分析

时间复杂度：O(R * C)，需要遍历整个 grid 网格。
空间复杂度：O(R * C)，在所有元素都是 1 的情况，需要遍历整个 grid 网格。

### 代码

```js
const maxAreaOfIsland = function (grid) {
    let max = 0;
    // 查找相邻元素
    const find = function (row, col) {
        if (grid[row] === void 0 || grid[row][col] === void 0 || grid[row][col] === 0) {
            return 0;
        }
        // 如果这个元素已经被统计过了，则在 grid 中修改为 0，避免下次重复计算
        grid[row][col] = 0;
        return 1 + find(row - 1, col) + find(row + 1, col) + find(row, col - 1) + find(row, col + 1);
    };
    for (let row = 0; row < grid.length; row++) {
        for (let col = 0; col < grid[row].length; col++) {
            max = Math.max(max, find(row, col));
        }
    }
    return max;
};
```