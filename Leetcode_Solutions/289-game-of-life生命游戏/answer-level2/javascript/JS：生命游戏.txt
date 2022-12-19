### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
    
    var gameOfLife = function(board) {
        let x_bias = [1 ,-1, 0, 0, 1, -1, 1, -1];
        let y_bias = [0, 0, 1, -1, 1, 1, -1, -1];
        let row = board[0].length;
        function check(i, j){
            let liveCell = 0;
            for (let k = 0; k < 8; k++){
                var i_bias = i + x_bias[k];
                var j_bias = j + y_bias[k];
                if (i_bias < 0 || j_bias < 0 || i_bias === board.length || j_bias === row){

                }else if (board[i_bias][j_bias] === 1){
                    liveCell++;
                }
            }
            if (board[i][j] === 1){
                if (liveCell < 2) return 0;
                if (liveCell === 2 || liveCell === 3) return 1;
                if (liveCell > 3) return 0;
            }else{
                if (liveCell === 3) return 1;
            }
            return board[i][j];
        }
        let res = [];
        for (let i = 0; i < board.length; i++){
            res[i] = [];
            for (let j = 0; j < row; j++){
                res[i][j] = 0;
            }
        }
        for (let i = 0; i < board.length; i++){
            for (let j = 0; j < row; j++){
                res[i][j] = check(i, j);
            }
        }
        for (let i = 0; i < board.length; i++){
            for (let j = 0; j < row; j++){
                board[i][j] = res[i][j];
            }
        }
        return board;
    };
```