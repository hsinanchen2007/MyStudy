
### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
//方向数组
var numRookCaptures = function(board) {
    let length = board.length;
    let num = 0;
    const dx = [0, -1, 0, 1];
    const dy = [-1, 0, 1, 0];
    let row, col, ri, rj;
    for(ri = 0; ri < length; ri++) {
        if(!board[ri].includes("R")) continue;
        rj = board[ri].indexOf("R"); 
        break;
    }
    for(let n = 0; n < dx.length; n++){
        for(let step = 1; step < length; step++){
            row = ri + step*dx[n];
            col = rj + step*dy[n];
            if(row<0 || row>=length || col<0 || col>=length || board[row][col]=="B") break;
            else if(board[row][col] == "p"){
                num++;
                break;
            }
        }
    }
    return num;
};


//先找到车的位置再向四周遍历, 优化 (56ms,33.4mb)
/*var numRookCaptures = function(board) {
    var length = board.length;
    var num = 0;
    for(var i = 0; i < length; i++) {
        if(!board[i].includes("R")) continue;
        var j = board[i].indexOf("R");
        //console.log({i,j});
        for(var n = j - 1; n > 0; n--) {
            if(board[i][n] == "B") break;
            else if(board[i][n] == "p") {
                num++;
                break;
            }
        }  
        for(n = j + 1; n < length; n++) {
            if(board[i][n] == "B") break;
            else if(board[i][n] == "p") {
                num++;
                break;
            }
        }
        for(n = i - 1; n > 0; n--) {
            if(board[n][j] == "B") break;
            else if(board[n][j] == "p") {
                num++;
                break;
            }
        }
        for(n = i + 1; n < length; n++) {
            if(board[n][j] == "B") break;
            else if(board[n][j] == "p") {
                num++;
                break;
            }
        }
        break;
    }
    return num;
};*/

//先找到车的位置再向四周遍历 (96ms,33.8mb)
/*var numRookCaptures = function(board) {
    var length = board.length;
    var ri, rj;
    var num = 0;
    outer:
    for(var i = 0; i < length; i++) {
        for(var j = 0; j < length; j++) {
            if(board[i][j] == "R") {
                ri = i;
                rj = j;
                break outer;
            }
        }
    }
    for(i = ri - 1; i > 0; i--) {
        if(board[i][rj] == "B"){
            break;
        }else if(board[i][rj] == "p") {
            num++;
            break;
        }
    }  
    for(i = ri + 1; i < length; i++) {
        if(board[i][rj] == "B"){
            break;
        }else if(board[i][rj] == "p") {
            num++;
            break;
        }
    }
    for(j = rj - 1; j > 0; j--) {
        if(board[ri][j] == "B"){
            break;
        }else if(board[ri][j] == "p") {
            num++;
            break;
        }
    }
    for(j = rj + 1; j < length; j++) {
        if(board[ri][j] == "B"){
            break;
        }else if(board[ri][j] == "p") {
            num++;
            break;
        }
    }
    return num;
};*/
```