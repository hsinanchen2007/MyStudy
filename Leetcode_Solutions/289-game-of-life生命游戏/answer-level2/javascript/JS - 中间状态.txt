### 解题思路
增加2个中间状态活变死,死变活

### 代码

```javascript
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function(board) {
    // 新增状态
    // 2 活变死
    // 3 死变活
    let m = board[0].length;
    let n = board.length;
    // 计算状态
    const clacStat = (x, y) => {
        // 获得周围存活的个数
        let liveNum = 0;
        let xArr = [];
        let yArr = [];
        if (x - 1 >= 0) {
            xArr.push(x - 1);
        }
        xArr.push(x);
        if (x + 1 < m) {
            xArr.push(x + 1);
        }
        if (y - 1 >= 0) {
            yArr.push(y - 1);
        }
        yArr.push(y);
        if (y + 1 < n) {
            yArr.push(y + 1);
        }
        for (let visitX of xArr) {
            for (let visitY of yArr) {
                if (visitX === x && visitY === y) {
                    continue;
                }
                let visitStat = board[visitY][visitX];
                if (visitStat === 1 || visitStat === 2) {
                    liveNum++;
                }
            }
        }
        if (board[y][x] === 1 && (liveNum < 2 || liveNum > 3)) {
            board[y][x] = 2;
        } else if (board[y][x] === 0 && liveNum === 3) {
            board[y][x] = 3;
        }
    }
    // 清算状态
    const transformStat  = (x, y) => {
        let stat = board[y][x];
        board[y][x] = {
            0: 0,
            1: 1,
            2: 0,
            3: 1,
        }[stat]
    };
    // 访便所有细胞执行函数
    const visitBoard = (cb) => {
        for (let y = 0; y < n; y++) {
            for (let x = 0; x < m; x++) {
                cb(x, y);
            }
        }
    }
    visitBoard(clacStat);
    visitBoard(transformStat);
    return board;
};
```