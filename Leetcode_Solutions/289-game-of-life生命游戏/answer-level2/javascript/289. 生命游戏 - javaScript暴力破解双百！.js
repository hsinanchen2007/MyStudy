### 解题思路
![image.png](https://pic.leetcode-cn.com/30167dde94a9f23c6f3c4c96c1096b665792059e82190a726dc465d2064a3dc6-image.png)
JavaScript暴力破解双百！

### 代码

```javascript
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function(board) {
    
    let clone = JSON.parse(JSON.stringify( board ))
    for( let i=0; i < board.length; i++ ){
        let row = board[i]
        for( let j=0; j<row.length; j ++ ){
            row[j] = handle(i,j,clone)
        }
    }
};

function handle( i,j,clone ){
    let n = clone[i][j]
    let live = 0; // 周围活的细胞
    if( clone[i-1] ){
        if( clone[i-1][j] == '1' ) live++;  // ↑
        if( clone[i-1][j+1] == '1' ) live++; // ↗
        if( clone[i-1][j-1] == '1' ) live++; // ↖
    }
    if( clone[i+1] ){
        if( clone[i+1][j+1] == '1' ) live++; // ↘
        if( clone[i+1][j] == '1' ) live++; // ↓
        if( clone[i+1][j-1] == '1' ) live++; // ↙
    }
    if( clone[i][j+1] == '1' ) live++; // →
    if( clone[i][j-1] == '1' ) live++; // ←

    if(n == 1 && ( live < 2 || live > 3 ) ) return 0
    else if( n == 0 && live == 3 ) return 1
    return n
}







```