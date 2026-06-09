使用两位二进制：第一位代表下一状态，第二位代表原数组细胞的状态
```
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function(board) {
    if(board.length<1)return;
    var row = board.length;
    var col = board[0].length;
    for(var i=0; i<row; i++){
        for(var j=0; j<col; j++){
            var lives = countLives( board, i, j );
            // live->live
            if((board[i][j] & 1) == 1){
                if(lives >= 2 && lives <= 3){
                    board[i][j] = 3;
                    console.log(board[i][j]);
                }
            }
            // dead->live
            else{
                if(lives==3){
                    board[i][j] = 2;
                }
            }
        }   
    }

// 取状态机第一位
    for(var i=0;i<row;i++){
            for(var j=0;j<col;j++){
                board[i][j] >>= 1;
            }
        }

//统计每个元素周围八个方向的活细胞总数的函数
    function countLives(b,u,v){
        var count=0;
        var directions=[[1,0],[-1,0],[0,1],[0,-1],[1,1],[1,-1],[-1,1],[-1,-1]];
        for(var m=0;m<8;m++){
            var x=u+directions[m][0];
            var y=v+directions[m][1];
            if(x<0||x>b.length-1||y<0||y>b[0].length-1){continue;}
            count +=(b[x][y] & 1);//使用两位的二进制状态机来表示，和1做与运算，得到的就是第二位（也就是原数组的值）
        }
        return count;
    }
};
```
