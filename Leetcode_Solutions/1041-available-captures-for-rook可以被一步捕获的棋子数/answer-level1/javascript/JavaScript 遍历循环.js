### 解题思路
- 通过 for 循环找到 R车 的位置
- 然后进行各个方向判断，如果先遇到 B大象 直接跳出这个方向的循环，如果已经遇到 p卒 也直接跳出本次循环（防止后续还会遇到第二个p卒）

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    let X,Y = 0
    let num = 0
    for(let i = 0; i < 8; i++){
        for(let j = 0; j < 8; j++){
            if(board[i][j] == 'R'){
                X = i
                Y = j
            }
        }
    }
    //从→，↓，←，↑ 顺序进行判断
    for(let i = Y; i < 8; i++){
        if(board[X][i] == 'B'){
            break;
        }
        if(board[X][i] == 'p') {
            num++
            break;
        }
    }
    for(let i = X; i < 8; i++){
        if(board[i][Y] == 'B'){
            break;
        }
        if(board[i][Y] == 'p') {
            num++
            break;
        }
    }
    for(let i = Y; i > 0; i--){
        if(board[X][i] == 'B'){
            break;
        }
        if(board[X][i] == 'p') {
            num++
            break;
        }
    }
    for(let i = X; i > 0; i--){
        if(board[i][Y] == 'B'){
            break;
        }
        if(board[i][Y] == 'p') {
            num++
            break;
        }
    }
    return num
    
    
};
```