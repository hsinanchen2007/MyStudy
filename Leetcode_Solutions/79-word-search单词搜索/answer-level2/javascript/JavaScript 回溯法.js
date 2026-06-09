### 解题思路
回溯算法

### 代码

```javascript
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
 var exist = function(board, word) {
            const bLen = board.length
            const aLen = board[0].length
            let isExist = false
            // 存储当前所选字母在平面内上下左右四个方向字母
            const d = [[-1, 0], [0, 1], [1, 0], [0, -1]]
            // 维护递归过程中，平面中字母的使用状态，每个只能使用一次
            const used = []
            // 判断所选字母是否在二维平面内
            const inArea = function (x, y) {
                return x >=0 && x < board.length && y >=0 && y < board[0].length
            }
            // 递归函数，判断board[i][j]开始移动，是否可以找到word
            const _exist = function (board, i, j, word) {
                const wLen = word.length
                if (wLen === 1 && board[i][j] === word[0]) {
                   isExist = true
                }
                if (board[i][j] === word[0]) {
                    const newWord = word.substring(1)
                    used[i][j] = true
                    for (let k = 0; k < 4; k++) {
                        const newX = i + d[k][0]
                        const newY = j + d[k][1]
                        inArea(newX, newY) && !used[newX][newY] && _exist(board, newX, newY, newWord)
                        if (isExist) {
                            return true
                        }
                    }
                    used[i][j] = false
                }
            }
            if (bLen) {
                for (let i = 0; i < bLen; i++) {
                    used[i] = new Array(aLen).fill(false)
                }
                for (let i = 0; i < bLen; i++) {
                    for (let j = 0; j < aLen; j++) {
                        _exist(board, i, j, word)
                    }
                }
            }
            return isExist
        };
```