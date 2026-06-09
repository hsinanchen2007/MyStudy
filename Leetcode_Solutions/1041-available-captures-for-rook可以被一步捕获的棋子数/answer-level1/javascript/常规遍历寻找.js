```js
var numRookCaptures = function(board) {
    //找到车的坐标，再依次遍历
    var x, y, flag = 0, res = 0;
    for(var i=0;i<board.length;i++){
        for(var j=0;j<board[0].length;j++){
            if(board[i][j] === 'R'){
                x = i;
                y = j;
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    //up
    var up = y;
    while(up > -1){
        if(board[x][up] === 'B'){
            break;
        }else if(board[x][up] === 'p'){
            res++;
            break;
        }
        up--;
    }
    //down
    var down = y;
    while(down < 8){
        if(board[x][down] === 'B'){
            break;
        }else if(board[x][down] === 'p'){
            res++;
            break;
        }
        down++;
    }
    //left
    var left = x;
    while(left > -1){
        if(board[left][y] === 'B'){
            break;
        }else if(board[left][y] === 'p'){
            res++;
            break;
        }
        left--;
    }
    //right
    var right = x;
    while(right < 8){
        if(board[right][y] === 'B'){
            break;
        }else if(board[right][y] === 'p'){
            res++;
            break;
        }
        right++;
    }
    return res;
};
```
