### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    let result=0,i=0,j=0;
    //1,直到R的位置
    outer:for(;i<board.length;i++){
        for(j=0;j<board[0].length;j++){
            if(board[i][j]==='R')
                break outer;
        }
    }
    //2，上下左右吃卒 
    for(let k=i-1;k>=0;k--){
        if(board[k][j]=='B')
            break;
        if(board[k][j]=='p'){
            result++;
            break;
        }
    }
    for(let k=i+1;k<board.length;k++){
        if(board[k][j]=='B')
            break;
        if(board[k][j]=='p'){
            result++;
            break;
        }

    }
    for(let k=j-1;k>=0;k--){
        if(board[i][k]=='B')
            break;
        if(board[i][k]=='p'){
                result++;
                break;
            }
    }
    for(let k=j+1;k<board[0].length;k++){
        if(board[i][k]=='B')
            break;
        if(board[i][k]=='p'){
                result++;
                break;
         }
    }
    return result;
};
```