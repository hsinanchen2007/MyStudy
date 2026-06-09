### 执行结果
![image.png](https://pic.leetcode-cn.com/2581b75f2c9adf8c11a2459bcae00fd10361a5881ff127c4ca47d04f3915bde4-image.png)

### 解题思路
1. 先遍历一遍二维数组，把所有的腐烂橘子的坐标存在 arr 数组中。
2. 遍历 arr 数组，按照坐标判断 grid 中相邻的四个位子是否有橘子且橘子没坏。如果有，则让其腐烂。

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function(grid) {
    let freshOrange = 0
    let times = 0;
    let arr = [];
    let row = grid.length;
    let column = grid[0].length;
    for (let i = 0; i < row; i++) {
        for (let j = 0; j < column; j++) {
            if (grid[i][j] === 2) {
                arr.push([i,j])
            }
            if (grid[i][j] === 1) {
                freshOrange++
            }
        }
    }

    let len = arr.length
    while(freshOrange && len) {
        times++
        for (let k = 0; k < len; k++) {
            let [i, j] = arr.shift()
            if ( (i+1) <  row && grid[i+1][j] === 1) {
                grid[i+1][j] = 2
                arr.push([i+1, j])
                freshOrange--
            }
            if ( (j+1) < column && grid[i][j+1] === 1 ) {
                grid[i][j+1] = 2
                arr.push([i, j+1])
                freshOrange--
            }
            if ( i > 0 && grid[i-1][j] === 1 ) {
                grid[i-1][j] = 2
                arr.push([i-1, j])
                freshOrange--
            }
            if ( j > 0 && grid[i][j-1] === 1 ) {
                grid[i][j-1] = 2
                arr.push([i, j-1])
                freshOrange--
            }
        }
        len = arr.length
    }
    if (freshOrange) {
        return -1
    }
    return times
};
```