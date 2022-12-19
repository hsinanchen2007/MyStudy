### 解题思路

找到车后开始捕猎，暴力

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    let res = 0
    for (let i = 0; i < 8; i++) {
        for (let j = 0; j < 8 ; j++) {
            if (board[i][j] === 'R') { // 发现车,开始狩猎
                // 北
                for (let n = i; n >= 0; n--) {
                    if (board[n][j] === 'B') {
                        break
                    }
                    if (board[n][j] === 'p') {
                        res++
                        break
                    }
                }
                // 南
                for (let n = i; n < 8; n++) {
                    if (board[n][j] === 'B') {
                        break
                    }
                    if (board[n][j] === 'p') {
                        res++
                        break
                    }
                }
                // 西
                for (let n = j; n >= 0; n--) {
                    if (board[i][n] === 'B') {
                        break
                    }
                    if (board[i][n] === 'p') {
                        res++
                        break
                    }
                }
                // 东
                for (let n = i; n < 8; n++) {
                    if (board[i][n] === 'B') {
                        break
                    }
                    if (board[i][n] === 'p') {
                        res++
                        break
                    }
                }
            }
        }
    }
    return res
};
```