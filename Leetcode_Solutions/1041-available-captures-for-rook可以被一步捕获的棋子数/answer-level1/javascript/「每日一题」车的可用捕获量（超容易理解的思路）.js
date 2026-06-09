### 解题思路
 先找到「车」，然后以此「车」 为中心，
 向上、下、左、右四个方向查找，
 只要找到不为「空方块」的就停下，
 此时如果是「卒」的话就计数
### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
/**
 * 思路：
 * 先找到「车」，然后以此「车」 为中心，
 * 向上、下、左、右四个方向查找，
 * 只要找到不为「空方块」的就停下，
 * 此时如果是「卒」的话就计数
 */
var numRookCaptures = function(board) {
    let len = board.length;
    let counnt = 0;
    // 车 的所在位置
    let x = 0, y = 0;
    for(let i = 0; i < len; i++){
        let index = board[i].indexOf("R");
        if(index > -1){
            x = i;
            y = index;
            break;
        }
    }
    // 定义四个方向
    let xLeftLen = x , xRightLen = x;
    let yTopLen = y , yBottomLen = y;
    // 左
    while(xLeftLen > 0){
        xLeftLen--;
        let x1 = board[xLeftLen][y];
        if( x1 != "."){
            if(x1 === "p"){
                counnt++;
            }
           break;
        }
    }
    // 右
    while(xRightLen < len - 1){
        xRightLen++;
        let x2 = board[xRightLen][y];
        if( x2 != "." ){
            if(x2 === "p"){
                counnt++;
            }
            break;
        }
    }
    // 上
    while(yTopLen > 0){
        yTopLen--;
        let y1 = board[x][yTopLen];
        if(y1 != "."){
            if(y1 === "p"){
                counnt++;
            }
            break;
        }
    }
    // 下
    while(yBottomLen < len - 1){
        yBottomLen++;
        let y2 = board[x][yBottomLen];
        if( y2 != "."){
            if(y2 === "p"){
                counnt++;
            }
            break;
        }
    }
    return counnt;
};
```