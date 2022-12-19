### 解题思路
由于不能新建数组，需要在当前数组进行操作，因此在更改细胞状态时将所有可能（0，1，0变1，1变0）情况按照分类记录下来，然后再来一遍，更改到合适状态。
两次遍历
第一次，遍历每个细胞，更改当前细胞状态，将所有可能情况进行记录，0 代表 原来为0状态未变；1 代表 原来为1状态未变；2代表原来为0状态变为1；3代表原来为1状态变为0；
第二次，根据上次遍历的状态变化情况，更改当前细胞状态；

### 代码

```javascript
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function(board) {
    var i = 0,j = 0;
    for(i = 0; i < board.length; i++){
        for(j = 0; j < board[i].length; j++){
            let tmp = 0;
            if(i && j) tmp += board[i-1][j-1] > 1 ? board[i-1][j-1] - 2 : board[i-1][j-1];
            if(i) tmp += board[i-1][j] > 1 ? board[i-1][j] - 2 : board[i-1][j];
            if(i && j < board[i].length - 1) tmp += board[i-1][j+1] > 1 ? board[i-1][j+1] - 2 : board[i-1][j+1];
            if(j) tmp += board[i][j-1] > 1 ? board[i][j-1] - 2 : board[i][j-1];
            if(j < board[i].length - 1) tmp += board[i][j+1] > 1 ? board[i][j+1] - 2 : board[i][j+1];
            if(i < board.length - 1 && j) tmp += board[i+1][j-1] > 1 ? board[i+1][j-1] - 2 : board[i+1][j-1];
            if(i < board.length - 1) tmp += board[i+1][j] > 1 ? board[i+1][j] - 2 : board[i+1][j];
            if(i < board.length - 1 && j < board[i].length - 1) tmp += board[i+1][j+1] > 1 ? board[i+1][j+1] - 2 : board[i+1][j+1];
            if(board[i][j]){
                if(tmp < 2 || tmp > 3) board[i][j] = 3;
            }else{
                if(tmp === 3) board[i][j] = 2;
            }
        }
    }
    for(i = 0; i < board.length; i++){
        for(j = 0; j < board[i].length; j++){
            if(board[i][j] > 1) board[i][j] = board[i][j] === 2 ? 1 : 0;
        }
    }
};
```