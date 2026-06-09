
![image.png](https://pic.leetcode-cn.com/121de2362bb839400a6051e4db9d2077a80ec48014e3e5756e53648d1cb76998-image.png)

```javascript
var numRookCaptures = function(board) {
    let [x, y, sum] = [0, 0, 0];
    let arr = [];
    //找到车所在的坐标
    for(let i = 0; i < 8; i ++) {
        if(board[i].indexOf('R') !== -1) {
            x = i;
            y = board[i].indexOf('R');
            break;
        }
    }
    //递归调用  碰到边界或者🐘则换一个方向，遇到小卒num + 1 调整方向满四次以后返回num
    const find = (a,b,board) => {
        if(arr.length === 4) return sum;
        if(board[a][b] === 'B') {
            arr.push(1);
            return find(x, y, board);
        }
        if(board[a][b] === 'p') {
            sum ++;
            arr.push(1);
            return find(x, y, board)
        }
        if(arr.length === 0 && a - 1 >= -1) {
            if(a - 1 === -1) {
                arr.push(1);
                return find(x, y, board);
            }
            return find(a - 1, b, board);
        }
        if(arr.length === 1 && a + 1 <= 8) {
            if(a + 1 === 8) {
                arr.push(1);
                return find(x, y, board);
            }
            return find(a + 1, b, board);
        }
        if(arr.length === 2 && b - 1 >= -1) {
            if(b - 1 === -1) {
                arr.push(1);
                return find(x, y, board);
            }
            return find(a, b - 1, board);
        }
        if(arr.length === 3 && b + 1 <= 8) {
            if(b + 1 === 8) {
                arr.push(1);
                return find(x, y, board);
            }
            return find(a, b + 1, board);
        }
    }
    return find(x,y,board)
};
```
