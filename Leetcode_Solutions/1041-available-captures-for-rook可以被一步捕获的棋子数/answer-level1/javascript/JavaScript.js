### 解题思路
分两个坐标轴分别识别最接近车的象棋，最后处理这四个识别结果。
### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    var res = 0;
    var i = 0,j = 0;
    var x = 0, y = 0;
    //找到车坐标
    for(i = 0; i < board.length; i++){
        for(j = 0; j < board[i].length;j++){
            if(board[i][j] == 'R'){
                x = i; y = j; break;
            }
        }
    }
    var tmp = 8;
    var perx = 0,pery = 0,nexx = 0,nexy = 0,flagx = 1, flagy = 1;
    //由x轴，y轴坐标最末尾开始向前遍历，找到最接近车的两个象或者卒，0代表无，1代表卒，2代表象；
    while(tmp--){
        if(board[x][tmp] == 'p'){
            if(flagy) pery = 1;
            else if(!nexy) nexy = 1;
        }
        else if(board[x][tmp] == 'B'){
            if(flagy) pery = 2;
            else if(!nexy) nexy = 2;
        }
        else if(board[x][tmp] == 'R'){
            flagy = 0;
        }

        if(board[tmp][y] == 'p'){
            if(flagx) perx = 1;
            else if(!nexx) nexx = 1;
        }
        else if(board[tmp][y] == 'B'){
            if(flagx) perx = 2;
            else if(!nexx) nexx = 2;
        }
        else if(board[tmp][y] == 'R'){
            flagx = 0;
        }
    }
    //四个方向最接近车的分别判定，如果是卒，则+1；
    if(perx === 1) res+=1;
    if(pery === 1) res+=1;
    if(nexx === 1) res+=1;
    if(nexy === 1) res+=1;
    return res;
};
```