### 解题思路
1：找到R的位置

2：根据R的位置进行上下左右移动，判断是否能一步吃到p

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    let num = 0;
    let x = 0;
    let y = 0;
    for (let i = 0; i < 8; i ++) {
        for (let j = 0; j < 8; j ++) {
            if (board[i][j] === 'R') {
                x = i;
                y = j;
            }
        }
    }

    // 向上移动
    for (let u = x; u >= 0; u --) {
        if (board[u][y] === '.') {
            continue;
        }
        if (board[u][y] === 'B') {
            break;
        }
        if (board[u][y] === 'p') {
            num ++;
            break;
        }
    }

    // 向下移动
    for (let d = x; d < 8; d ++) {
        if (board[d][y] === '.') {
            continue;
        }
        if (board[d][y] === 'B') {
            break;
        }
        if (board[d][y] === 'p') {
            num ++;
            break;
        }
    }

    // 向左移动
    for (let l = y; l >= 0; l --) {
        if (board[x][l] === '.') {
            continue;
        }
        if (board[x][l] === 'B') {
            break;
        }
        if (board[x][l] === 'p') {
            num ++;
            break;
        }
    }

    // 向右移动
    for (let r = y; r < 8; r ++ ) {
        if (board[x][r] === '.') {
            continue;
        }
        if (board[x][r] === 'B') {
            break;
        }
        if (board[x][r] === 'p') {
            num ++;
            break;
        }
    }
    return num;
};
```