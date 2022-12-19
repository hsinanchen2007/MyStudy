### 解题思路
![image.png](https://pic.leetcode-cn.com/2956cffc25d93d56e671bf4c875f162b5fdce252d0c0cf4a47e1f28665be80b5-image.png)

直接干，没绕啥弯子。。。

### 代码

```javascript
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function(board) {
    const width = board[0].length;
    const height = board.length;
    const scanLive = (m, n) => {
        let live = 0;

        if (m + 1 < height && board[m + 1][n] === 1) live++;
        if (m - 1 >= 0 && board[m - 1][n] === 1) live++;
        if (n + 1 < width && board[m][n + 1] === 1) live++;
        if (n - 1 >= 0 && board[m][n - 1] === 1) live++;

        if (m + 1 < height && n + 1 < width && board[m + 1][n + 1] === 1) live++;
        if (m - 1 >= 0 && n - 1 >= 0 && board[m - 1][n - 1] === 1) live++;
        if (m + 1 < height && n - 1 >= 0 && board[m + 1][n - 1] === 1) live++;
        if (m - 1 >= 0 && n + 1 < width && board[m - 1][n + 1] === 1) live++;

        return live;
    }

    let toLive = [],
        toDead = [];

    board.forEach((row, i) => {
        row.forEach((val, j) => {
            if (val === 1 && scanLive(i, j) < 2) toDead.push([i, j]);
            if (val === 1 && scanLive(i, j) > 3) toDead.push([i, j]);
            if (val === 0 && scanLive(i, j) === 3) toLive.push([i, j]);
        })
    })
    toLive.forEach((val) => {
        board[val[0]][val[1]] = 1;
    })
    toDead.forEach((val) => {
        board[val[0]][val[1]] = 0;
    })
};
```