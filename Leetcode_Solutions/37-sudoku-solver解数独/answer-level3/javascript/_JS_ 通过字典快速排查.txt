### 解题思路
根据上题，先形成行、列、块字典，并缓存对应点的值
然后构建数组堆，缓存预处理的值，如果在遍历的时候发现当前值无法满足矩阵构建，就返回上一个结果值重新计算。

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {boolean}
 */
var solveSudoku = function(board) {
    var col = [],
        row = [],
        sqa = [];
    var board2 = [];
    // 初始化
    for (var i = 0; i < board.length; i++) {
        for (var j = 0; j < board[i].length; j++) {
            var n = board[i][j];
            var si = Math.floor(j / 3) + Math.floor(i / 3) * 3
            if (!row[i]) {
                row[i] = {}
            }
            if (n !== '.') {
                row[i][n] = true;
            }

            if (!col[j]) {
                col[j] = {};
            }
            if (n !== '.') {
                col[j][n] = true;
            }

            if (!sqa[si]) {
                sqa[si] = {};
            }
            if (n !== '.') {
                sqa[si][n] = true;
            }
        }
    }

    // 初始化
    for (var i = 0; i < board.length; i++) {
        for (var j = 0; j < board[i].length; j++) {}
    }
    var index = 0,
        k = 1
    while (index < 81) {
        var i = Math.floor(index / 9);
        var j = index % 9;
        var si = Math.floor(j / 3) + Math.floor(i / 3) * 3
        if (board[i][j] !== '.') {
            index++;
        } else {
            for (; k <= 10; k++) {
                if (k == 10) {
                    // 如果到顶了，回退
                    var o = board2.pop(),
                        _i = o.i,
                        _j = o.j,
                        _k = o.k,
                        _si = o.si;
                    k = _k + 1;
                    board[_i][_j] = '.'
                    row[_i][_k] = false;
                    col[_j][_k] = false;
                    sqa[_si][_k] = false;
                    index = o.index;
                    break;
                } else if (!row[i][k] && !col[j][k] && !sqa[si][k]) {
                    row[i][k] = true;
                    col[j][k] = true;
                    sqa[si][k] = true;
                    board[i][j] = '' + k;
                    board2.push({
                        index,
                        si,
                        i,
                        j,
                        k
                    });
                    index++;
                    k = 1;
                    break;
                }
            }
        }
    }
    return board;
};
```