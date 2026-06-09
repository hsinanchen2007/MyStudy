### 解题思路
此方法复杂度还是太高，逻辑还算清晰，关于数组解法可以考虑位运算

### 代码

```javascript
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function(board) {

    if(board.length === 0) return board;

    let k = 0;

    // 原地处理数组，用于记录生命状态 -1:1->0, -2:1->1, -3:0->0, -4:0->1，其实仔细想一下定义两个状态就够，比如：2：该点上一次是1，3：该点上一次是0
    // 同时对于不受影响的数据进行恢复，比如当前节点的上面的上面的节点，剩下的是对剩余两行的恢复，因为我试过从零恢复，时间复杂度会多一些，现在是从72->64略微提升，但是速度依然不高

    for(let i = 0; i < board.length; i++) {
        for(let j = 0; j < board[i].length; j++) {
            helper(i,j, board, board.length, board[i].length);
            if(i >= 2) {
                const cur = board[i-2][j];
                if(cur === -1 || cur === -3) {
                    board[i-2][j] = 0;
                } else if(cur === -2 || cur === -4) {
                    board[i-2][j] = 1;
                }
            } 
        }
        if(i >= 2) {
            k++;
        }
    }

    for(let i = k; i < board.length; i++) {
        for(let j = 0; j < board[i].length; j++) {
            const cur = board[i][j];
            if(cur === -1 || cur === -3) {
                board[i][j] = 0;
            } else if(cur === -2 || cur === -4) {
                board[i][j] = 1;
            }
        }
    }
    
    return board;
};


const helper = (curX, curY, nums, row, column) => {
    let count = 0;
    let cur = nums[curX][curY];
    
    // 很显然的计数
    for(let i = curX - 1; i < curX + 2; i++) {
        for(let j = curY - 1; j < curY + 2; j++) {
            if(i === curX && j === curY) continue;
            if(isValid(i, j, row, column)) {
                if(nums[i][j] === 1 || nums[i][j] === -1 || nums[i][j] === -2) {
                    count ++;
                }
            }
        }
    }

    // Live Or Die

    if(cur === 1) {
        if(count < 2 || count > 3) {
            nums[curX][curY] = -1;
        } else {
            nums[curX][curY] = -2;
        }
    }
    else if(cur === 0) {
        if(count === 3) {
            nums[curX][curY] = -4;
        } else {
            nums[curX][curY] = -3;
        }
    }
}

// 判断越界
const isValid = (i, j, row, column) => {
    if(i < 0 || j < 0 || i >= row || j >= column) {
        return false;
    }
    return true;
}
```