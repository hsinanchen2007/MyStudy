### 解题思路
执行用时 :
96 ms, 在所有 JavaScript 提交中击败73.30%的用户
内存消耗 :38.1 MB, 在所有 JavaScript 提交中击败了100.00%的用户

### 代码

```javascript
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
    if(word.length == 0) return true;
    if(board.length == 0 ) return false;
    var rows = board.length;
    var cols = board[0].length;
    var res = false;
    //var wordLen = word.length;
    //从任意格可出发
    for(let i = 0; i<rows; i++){
        for(let j=0; j<cols; j++){
        var res0 = dfs(board,word,rows,cols,i,j,0);
        if(res0) {return true;}
        }
    }
    return false;
};
var dfs = function(board,word,rows,cols,row,col,i){
    if(row >= rows || row < 0){return false;}
    if(col >= cols || col < 0){return false;}
   // if(i >= word.length ){return false;}//??zaijiancha

    if(word[i] == board[row][col]){
        var tmp =  board[row][col];
        board[row][col]=null;
        var res = true;
        if(i+1 == word.length){return true;}
        if(i+1 < word.length){
            res = dfs(board,word,rows,cols,row-1,col,i+1) 
            || dfs(board,word,rows,cols,row+1,col,i+1)
            || dfs(board,word,rows,cols,row,col-1,i+1) 
            || dfs(board,word,rows,cols,row,col+1,i+1) ;
            }
        board[row][col]=tmp;//从任意格出发，所以需要多次遍历！所以要恢复
        return res;
    }
return false;

}
```