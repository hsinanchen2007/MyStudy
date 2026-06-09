### 解题思路
新增状态表示前后变化情况

### 代码

```javascript
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function (board) {
    // -1 --> 活->死
    // 0  --> 死->死
    // 1  --> 活->活
    // 2  --> 死->活
    let neighbor = [-1, 0, 1]
    let row = board.length
    let col = board[0].length
    for (let i = 0; i < row; i++) {
        for (let j = 0; j < col; j++) {
            let liveNeighbors = 0
            for (let x = 0; x < 3; x++) {
                for (let y = 0; y < 3; y++) {
                    let r = i + neighbor[x]
                    let c = j + neighbor[y]
                    if (r >= row || r < 0 || c >= col || c < 0 || (r === i && c === j)) {
                        continue
                    }
                    if (board[r][c] === -1 || board[r][c] === 1) {
                        liveNeighbors++
                    }
                }
            }
            //死 -> 活
            if (board[i][j] === 0 && liveNeighbors === 3) {
                board[i][j] = 2
            }
            //活 -> 死
            if (board[i][j] === 1 && (liveNeighbors > 3 || liveNeighbors < 2)) {
                board[i][j] = -1
            }

        }
    }
    for (let r = 0; r < row; r++) {
        for (let c = 0; c < col; c++) {
            if (board[r][c] > 0) {
                board[r][c] = 1
            } else {
                board[r][c] = 0
            }
        }
    }

    return board
};
```