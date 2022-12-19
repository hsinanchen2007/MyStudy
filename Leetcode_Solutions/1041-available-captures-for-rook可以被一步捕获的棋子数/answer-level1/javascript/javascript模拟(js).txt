模拟
思路和算法

根据题意模拟即可：

遍历棋盘确定白色车的下标，用 (st,ed)(st,ed) 表示。

模拟车移动的规则，朝四个基本方向移动，直到碰到卒或者白色象或者碰到棋盘边缘时停止，用 \textit{cnt}cnt 记录捕获到的卒的数量。

那么如何模拟车移动的规则呢？我们可以建立方向数组表示在这个方向上移动一步的增量，比如向北移动一步的时候，白色车的 x 轴坐标减 1，而 y 轴坐标不会变化，所以我们可以用 (-1, 0) 表示白色车向北移动一步的增量，其它三个方向同理。建立了方向数组，则白色车在某个方向移动 \textit{step}step 步的坐标增量就可以直接计算得到，比如向北移动 \textit{step}step 步的坐标增量即为 (-step, 0)。

方向数组也可以根据相应的题意自行扩展，比如模拟象棋中马跳的坐标增量。


```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    let num = 0;
    let R_i;
    let R_j;
    for (let i = 0; i < 8; i++) {
        if (R_i) {
            break;
        }
        for (let j = 0; j < 8; j++) {
            if (board[i][j] === 'R') {
                R_i = i;
                R_j = j;
                break;
            }
        }
    }
    const arr_i = [1, -1, 0, 0];
    const arr_j = [0, 0, 1, -1];
    for (let k = 0; k < 4; k++) {
        for (let step = 1; ; step++) {
            const r_i = R_i + step * arr_i[k];
            const r_j = R_j + step * arr_j[k];
            if (r_i < 0 || r_i >= 8 || r_j < 0 || r_j >= 8 || board[r_i][r_j] === 'B') {
                break;
            }
            if (board[r_i][r_j] === 'p') {
                num++;
                break;
            }
        }
    }
    return num;
};
```