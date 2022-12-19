### 解题思路
回溯算法

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var totalNQueens = function(n) {
    if (n < 1) {
        return []
    }
    let count = 0
    // 初始化一个棋盘
    const board = []
    for (let i = 0; i < n; i++) {
        board.push(new Array(n).fill('.'))
    }
    // 维护棋盘上每一列的占用情况
    const col = new Array(n).fill(false)
    // 维护从左下角到右上角的对角线占用情况
    const diagonal1 = new Map()
    // 维护从左上角到右下角的对角线占用情况
    const diagonal2 = new Map()
    // 初始化两个对角线map
    for (let j = 0; j < n; j++) {
        diagonal1.set(0+j, false)
        // 转为正数
        diagonal2.set(0-j+n-1, false)
    }
    for (let i = 1; i < n; i++) {
        diagonal1.set(i+n-1, false)
    }
    for (let i = 1; i < n; i++) {
        diagonal2.set(i + n - 1, false)
    }
    // 判断越界问题
    const inArea = function (x) {
        return x >= 0 && x < n
    }
    const _solveNQueens = function (board, i, j, line) {
        // 改变棋盘格内容为Q,维护状态更新
        board[i][j] = 'Q'
        col[j] = true
        diagonal1.set(i + j, true)
        diagonal2.set(i - j + n - 1, true)
        const newLine = [...line]
        newLine.push(board[i].join(''))
        // 已经找到一种结果时，数量加一
        if (newLine.length === n) {
            count ++
        } else {
            for (let k = 0; k < n; k++) {
                inArea(i + 1) && !col[k] && !diagonal1.get(i + 1 + k) 
                    && !diagonal2.get(i + 1 - k + n - 1) && _solveNQueens(board, i + 1, k, newLine)
            }
        }
        // 恢复棋盘格内容，恢复之前状态，进行回溯
        board[i][j] = '.'
        col[j] = false
        diagonal1.set(i + j, false)
        diagonal2.set(i - j + n - 1, false)
        return
    }

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            _solveNQueens(board, i, j, [])
        }
    }
    return count
};
```