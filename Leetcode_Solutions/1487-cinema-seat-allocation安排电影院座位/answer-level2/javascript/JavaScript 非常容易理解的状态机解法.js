空间不足以装下所有的座位状态来判断，但是如果每行只是维护一个状态变量是够的。

默认每排可以安排 2 个，维护一个状态机，当状态发生改变时调整总体的 count

例如当某一排状态为 STATE_LEFT_OR_CENTER（安排左边的连坐或者中间） 时，这排可以安排一个家庭。
此时 4 或者 5 位被占，则意味着从 1 个变成了 0 个，状态变成 STATE_ZERO，总 count - 1

```js
/**
 * @param {number} n
 * @param {number[][]} reservedSeats
 * @return {number}
 */
var maxNumberOfFamilies = function(n, reservedSeats) {
    if (n === 0) {
        return 0;
    }
   
    let count = n * 2;
   
    let stateMap = [];
    
    const STATE_ZERO = 0;
    const STATE_LEFT_OR_CENTER = 5;
    const STATE_RIGHT_OR_CENTER = 6;

    const STATE_CENTER = 2;
    const STATE_LEFT = 3;
    const STATE_RIGHT = 4;
    
    while (reservedSeats.length > 0) {
        const [x, y] = reservedSeats.pop();
        
        if (y === 1 || y === 10) {
            // pass
        } else {
            if (stateMap[x] === undefined) {
                if (y === 2 || y === 3) {
                    stateMap[x] = STATE_RIGHT_OR_CENTER;
                    count --;
                } else if (y === 8 || y === 9) {
                    stateMap[x] = STATE_LEFT_OR_CENTER;
                    count --;
                } else if (y === 4 || y === 5) {
                    stateMap[x] = STATE_RIGHT;
                    count --;
                } else if (y === 6 || y === 7) {
                    stateMap[x] = STATE_LEFT;
                    count --;
                }
            } else if (stateMap[x] === STATE_RIGHT_OR_CENTER) {
                if (y === 4 || y === 5) {
                    stateMap[x] = STATE_RIGHT;
                } else if (y === 8 || y === 9) {
                    stateMap[x] = STATE_CENTER;
                } else if (y === 6 || y === 7) {
                    stateMap[x] = STATE_ZERO;
                    count --;
                }
            } else if (stateMap[x] === STATE_LEFT_OR_CENTER) {
                if (y === 6 || y === 7) {
                    stateMap[x] = STATE_LEFT;
                } else if (y === 2 || y === 3) {
                    stateMap[x] = STATE_CENTER;
                } else if (y === 4 || y === 5) {
                    stateMap[x] = STATE_ZERO;
                    count --;
                }
            } else if (stateMap[x] === STATE_LEFT) {
                if (y === 2 || y === 3 || y === 4 || y === 5) {
                    stateMap[x] = STATE_ZERO;
                    count --;
                }
            } else if (stateMap[x] === STATE_RIGHT) {
                if (y === 6 || y === 7 || y === 8 || y === 9) {
                    stateMap[x] = STATE_ZERO;
                    count --;
                }
            } else if (stateMap[x] === STATE_CENTER) {
                if (y === 4 || y === 5 || y === 6 || y === 7) {
                    stateMap[x] = STATE_ZERO;
                    count --;
                }
            }
        }
    }
    
    return count;
};
```
