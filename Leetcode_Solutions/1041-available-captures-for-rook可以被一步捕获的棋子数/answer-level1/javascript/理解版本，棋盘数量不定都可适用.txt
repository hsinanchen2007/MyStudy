### 解题思路
1.先获取白车（R）所在的行和列
2.分别对白车的行和列进行上下左右分别遍历
3.代码可简化，此为理解版本
4.不只适用与8*8的棋盘，任何棋盘数量均可。

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
 var numRookCaptures = function(board) {
    // 获取白车所在的行和列
    let RIndex = getRIndex(board);
    console.log(RIndex);
    // 第x行可以吃的个数
    let numX = getXNum(board,RIndex[0],RIndex[1]);
    // 第Y列可以吃的个数
    let numY = getYNum(board,RIndex[0],RIndex[1]);
    return numX+numY;
};

// 获取R所在的行和列
function getRIndex(board) {
    let x = 0;
    let y = 0;
    for(let i=0;i<board.length;i++) {
        for(let j=0;j<board[i].length;j++) {
            if(board[i][j]==='R') {
                x = i;
                y = j;
                return [x,y];
            }
        }
    }
}

function getXNum(board,x,y) {
    let num1 = getSmall(board,x,y);
    let num2 = getLarge(board,x,y);
    return num1+num2;
}

function getYNum(board,x,y) {
    let num1 = getTop(board,x,y);
    let num2 = getBottom(board,x,y);
    return num1+num2;
}

function getSmall(board,x,y) {
    // 第X行往左遍历
    let canEatNum = 0;
    for(let i=y;i>=0;i--) {
        if(board[x][i]==='p') {
            canEatNum += 1;
            return canEatNum;
        } else if(board[x][i]==='B') {
            return canEatNum;
        }else if(board[x][i]==='.' && (i===0)) {
            return canEatNum;
        }
    }
}

function getLarge(board,x,y) {
    // 第X行往右边遍历
    let canEatNum = 0;
    for(let i=y;i<board[x].length;i++) {
        if(board[x][i]==='p') {
            canEatNum += 1;
            return canEatNum;
        } else if(board[x][i]==='B') {
            return canEatNum;
        }else if(board[x][i]==='.' && (i===(board[x].length-1))) {
            return canEatNum;
        }
    }
}

function getTop(board,x,y) {
    // 第Y列往上遍历
    let canEatNum = 0;
    for(let i=x;i>=0;i--) {
        if(board[i][y]==='p') {
            canEatNum += 1;
            return canEatNum;
        } else if(board[i][y]==='B') {
            return canEatNum;
        }else if(board[i][y]==='.' && (i===0)) {
            return canEatNum;
        }
    }
}

function getBottom(board,x,y) {
    // 第Y列往下遍历
    let canEatNum = 0;
    for(let i=x;i<board.length;i++) {
        if(board[i][y]==='p') {
            canEatNum += 1;
            return canEatNum;
        } else if(board[i][y]==='B') {
            return canEatNum;
        }else if(board[i][y]==='.' && (i===(board.length-1))) {
            return canEatNum;
        }
    }
}
```