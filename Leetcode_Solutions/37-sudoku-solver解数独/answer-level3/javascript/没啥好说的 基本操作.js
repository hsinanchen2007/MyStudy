### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */

var solveSudoku = function (board = [[]]) {
    // 待解决的位置
    var stack = []
    // 初始化stack,顺便处理一次board
    function initStack(board) {
        board.forEach((row, i) => {
            row.forEach((item, j) => {
                if (item == '.') {
                    var mayBeList = check(i, j);
                    if (mayBeList.length > 1) {
                        stack.push([i, j])
                    } else if (mayBeList.length == 1) {
                        board[i][j] = mayBeList[0]
                    }
                }
            })
        });
    }
    // 通过set计算所有可能值
    function check(i, j) {
        var set = new Set(['1', '2', '3', '4', '5', '6', '7', '8', '9']);
        // 横向去重
        for (let index = 0; index < board[0].length; index++) {
            const val = board[i][index];
            if (set.has(val)) {
                set.delete(val)
            }
        }
        // 纵向去重
        for (let index = 0; index < board.length; index++) {
            const val = board[index][j];
            if (set.has(val)) {
                set.delete(val)
            }
        }
        let startRow = 0, endRow = 0;
        let startCol = 0, endCol = 0;
        if (i < 3) {
            startCol = 0; endCol = 2
        } else if (i >= 3 && i < 6) {
            startCol = 3; endCol = 5
        } else {
            startCol = 6; endCol = 8
        }
        if (j < 3) {
            startRow = 0; endRow = 2
        } else if (j >= 3 && j < 6) {
            startRow = 3; endRow = 5
        } else {
            startRow = 6; endRow = 8
        }
        for (let ii = startRow; ii <= endRow; ii++) {
            for (let jj = startCol; jj <= endCol; jj++) {
                const val = board[jj][ii];
                if (set.has(val)) {
                    set.delete(val)
                }
            }
        }
        return [...set];
    }
    // 通用处理 return 0 失败; return 1 成功
    function handle() {
        while (stack.length > 0) {
            var resolve = 0;
            var minItem = null;
            for (let i = 0; i < stack.length; i++) {
                var key = stack.shift();
                var mayBeList = check(key[0], key[1]);
                if (mayBeList.length == 0) {
                    return 0;
                }
                else if (mayBeList.length == 1) {
                    resolve++;
                    board[key[0]][key[1]] = mayBeList[0]
                } else {
                    if (!minItem || mayBeList.length < minItem.mayBeList.length) {
                        minItem = {
                            mayBeList,
                            key
                        }
                    }
                    stack.push(key)
                }
            }
            if (resolve == 0) {
                if (!tryOnWay(minItem)) {
                    return 0
                };
            }
        }
        return 1;
    }
    // 当所有未知位置的可能只大于等于2时,进行假设处理，失败后回溯
    function tryOnWay({ key = [], mayBeList = [] }) {
        var cBoard = clone(board);
        stack.splice(stack.indexOf(key), 1)
        var cStack = clone(stack);
        var success = 0;
        for (const value of mayBeList) {
            board[key[0]][key[1]] = value;
            var res = handle();
            if (res) {
                success++;
                break;
            } else {
                console.error('假设', key[0] + ',', key[1] + ' == ' + value + '是错误的');
                resetArrays(board, cBoard);
                stack = cStack;
            }
        }
        return success;
    }
    // 克隆函数
    function clone(arrays) {
        // return JSON.parse(JSON.stringify(value));
        var res = [];
        for (array of arrays) {
            var tmp = [];
            for (value of array) {
                tmp.push(value);
            }
            res.push(tmp)
        }
        return res;
    }
    // 回溯函数
    function resetArrays(tar, src) {
        for (let i = 0; i < src.length; i++) {
            for (let j = 0; j < src[i].length; j++) {
                tar[i][j] = src[i][j];
            }
        }
    }
    initStack(board);
    handle();
};

```