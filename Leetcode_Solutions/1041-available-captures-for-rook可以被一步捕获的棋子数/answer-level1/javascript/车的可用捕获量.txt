### 解题思路
找到R，然后往四个方向查找。
详见注释

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    // 方向数组
    let dx = [-1, 0, 1, 0];
    let dy = [0, 1, 0, -1];
    // 初始化结果
    let result = 0;
    for (let i = 0; i < 8; i++) {
        for (let j = 0; j < 8; j++) {
            // 寻找R
            if (board[i][j] === 'R') {
                // 开始遍历上右下左四个方向
                for (let d = 0; d < 4; d++) {
                    let x = i;
                    let y = j;
                    while(true) {
                        x += dx[d];
                        y += dy[d];
                        // 棋盘边缘判断
                        if (x < 0 || x >=8 || y < 0 || y >= 8) {
                            break;
                        }
                        // 遇到了B 结束查找
                        if (board[x][y] === 'B') {
                            break;
                        }
                        // 遇到p 结果+1
                        if (board[x][y] === 'p') {
                            result++;
                            // 注意，只能吃一个p，所以要break掉
                            break;
                        }
                    }
                }
                return result;
            }
        }
    }
};
```