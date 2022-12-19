### 解题思路
这难道只是简单的循环遍历查找？
1. 找到车（R）的位置；
2. 以此位置向四个方向去找卒（p）；
3. 遇到象就停止；
4. 遇到卒就吃掉

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    let total = 0;
    for (let i = 0; i<board.length; i++) {
        for (let j = 0; j < board[i].length; j++) {
            if (board[i][j] === 'R') {
                //西
                let left = j;
                while (--left >=0) {
                    if (board[i][left] === 'B') {
                        break;
                    }
                    if (board[i][left] === 'p') {
                        total++;
                        break;
                    }
                }
                let right = j;
                while (++right < 8) {
                    if (board[i][right] === 'B') {
                        break;
                    }
                    if (board[i][right] === 'p') {
                        total++;
                        break;
                    }
                }
                let north = i;
                while (--north >= 0) {
                    if (board[north][j] === 'B') {
                        break;
                    }
                    if (board[north][j] === 'p') {
                        total++;
                        break;
                    }
                }
                let south = i;
                while (++south < 8) {
                    if (board[south][j] === 'B') {
                        break;
                    }
                    if (board[south][j] === 'p') {
                        total++;
                        break;
                    }
                }

            }
        }
    }

    return total;
};
```