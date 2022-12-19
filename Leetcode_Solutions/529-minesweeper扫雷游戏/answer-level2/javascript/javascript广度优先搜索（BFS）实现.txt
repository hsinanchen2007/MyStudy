
```
/**
 * @param {character[][]} board
 * @param {number[]} click
 * @return {character[][]}
 */
var updateBoard = function(board, click) {
    var nr = board.length;
    var nc = board[0].length;
    // 八个方向
    var dr = [0, 1, 1, 1, 0, -1, -1, -1];
    var dc = [1, 1, 0, -1, -1, -1, 0, 1];
    var queue = [];
    
    queue.push(click);
    
    while(queue.length) {
        var [r, c] = queue.shift();
        // 炸D数
        var z = 0;

        if (board[r][c] === 'M') {
            board[r][c] = 'X';
        } else if (board[r][c] === 'E') {
            // 暂存方向，当有炸D时再合并到queue里
            let temp = [];
            
            for (var i = 0; i < 8; i++) {
                let tr = r + dr[i];
                let tc = c + dc[i];
                // 边界判断
                if (tr >= 0 && tr < nr && tc >= 0 && tc < nc) {
                    if (board[tr][tc] === 'E') {
                        temp.push([tr, tc]);
                    } else if (board[tr][tc] === 'M') {
                        z++;       
                    }
                }
            }

            if (z > 0) {
                board[r][c] = z + '';
            } else {
                board[r][c] = 'B';
                queue = queue.concat(temp);
            }
        }
    }
    
    return board;
};
```
