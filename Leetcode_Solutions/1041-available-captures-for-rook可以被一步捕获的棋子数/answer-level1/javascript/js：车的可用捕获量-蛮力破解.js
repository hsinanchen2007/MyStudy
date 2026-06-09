### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    let R_xpos = 0;
    let R_ypos = 0;
    for(let i = 0; i < 8; i++){
        for(let j = 0; j < 8; j++){
            if(board[i][j] === "R"){
                R_xpos = i;
                R_ypos = j;
                break;
            }
        }
    }
    let count = 0;
    for(let i = R_ypos; i >= 0; i--){
        //往上找
        if(board[R_xpos][i] === 'B'){
            break;
        }
        if(board[R_xpos][i] === 'p'){
            count+=1;
            break;
        }
    }
    for(let i = R_ypos; i < 8; i++){
        //往下找
        if(board[R_xpos][i] === 'B'){
            break;
        }
        if(board[R_xpos][i] === 'p'){
            count+=1;
            break;
        }
    }
    for(let i = R_xpos; i >= 0; i--){
        //go left
        if(board[i][R_ypos] === 'B'){
            break;
        }
        if(board[i][R_ypos] === 'p'){
            count+=1;
            break;
        }
    }
    for(let i = R_xpos; i <8; i++){
        //go right
        if(board[i][R_ypos] === 'B'){
            break;
        }
        if(board[i][R_ypos] === 'p'){
            count+=1;
            break;
        }
    }
    return count;
};
```