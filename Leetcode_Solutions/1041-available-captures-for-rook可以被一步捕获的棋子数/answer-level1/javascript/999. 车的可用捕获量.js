### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    let x = y = 0, len = board.length
    for(let i = 0; i < len; i++){
        for(let j = 0; j < len; j++){
            if(board[i][j] === 'R'){
                x = i
                y = j
                break
            }
        }
    }
    let posX = [-1, 1, 0, 0]
    let posY = [0, 0, 1, -1]
    let result = 0
    for(let f = 0; f < 4; f++){
        for(let step = 1; ;step++){
            let pX = x + posX[f] * step
            let pY = y + posY[f] * step
            if(pX < 0 || pX >= len || pY < 0 || pY >=len || board[pX][pY] === 'B'){
                break
            }
            if(board[pX][pY] === 'p'){
                result++
                break
            }    
        }
    }
    return result
};
```