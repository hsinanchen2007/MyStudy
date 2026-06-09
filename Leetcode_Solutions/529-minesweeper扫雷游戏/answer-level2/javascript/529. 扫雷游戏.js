### 解题思路

- 遇到 ``E`` 就检测周围的地雷数量，有地雷就把 ``E`` 改为周围对应的地雷数量，如果周围没有地雷就把它改成 ``B``，然后接着 ``递归`` 周围的格子

⚠️注意：这里的周围指的是 $8$ 个方向，``递归`` 的时候也是需要 ``递归`` $8$ 个方向。

### 代码

```javascript
/**
 * @param {string[][]} board
 * @param {number[]} click
 * @return {string[][]}
 */
var updateBoard = function(board, click) {
    /**
     * 计算位置 [row, col] 周围的地雷数量
     * @param {number} row
     * @param {number} col
     * @return {number}
     */
    const countMineAround = (x, y) => {
        let count = 0
        for (let i = 0; i < 8; i++) {
            const r = x + rowDir[i]
            const c = y + colDir[i]
            // 周围有地雷就自增 count
            if (r >= 0 && r < row && c >= 0 && c < col) {
                if (board[r][c] === 'M') {
                    count++
                }
            }
        }
        return count
    }
    /**
     * 递归排雷
     * @param x
     * @param y
     */
    const helper = (x, y) => {
        // 超出边界时结束递归
        if (x < 0 || x >= row || y < 0 || y >= col) {
            return
        }
        // 点到地雷时结束递归
        if (board[x][y] === 'M') {
            board[x][y] = 'X'
            return
        }
        // 只展开未点开的格子
        // 首先计算周围（8 个方向）的地雷数量
        // 如果周围不存在地雷，那么当前是空的格子（置为 'B'），同时递归周围（8 个方向）的格子
        // 如果周围至少存在一颗地雷，那么把数量找出来，并填到当前的格子里
        if (board[x][y] === 'E') {
            let count = countMineAround(x, y)
            if (count >= 1) {
                board[x][y] = count.toString()
            } else {
                board[x][y] = 'B'
                // 递归 8 个方向
                for (let i = 0; i < 8; i++) {
                    helper(x + rowDir[i], y + colDir[i])
                }
            }
        }
    }
    const row = board.length
    const col = board[0].length
    // 8 个方向
    const rowDir = [ -1, 0, 1, 1, -1, -1, 0, 1]
    const colDir = [ 0, -1, 1, -1, 1, -1, 1, 0]
    // 以当前点击的格子为起点开始递归
    helper(click[0], click[1])
    return board
};

```