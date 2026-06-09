```JavaScript
/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function(n) {
    // 初始化数组
    var arr = [];
    for (let i = 0; i <= n + 1; i++) {
        arr[i] = [];
        for (let j = 0; j <= n + 1; j++) {
            if (i === 0 || j === 0 || i === n + 1 || j === n + 1) {
                arr[i][j] = -1;
            } else {
                arr[i][j] = 0;
            }
        }
    }
    // 定义方向
    var up = false;
    var down = false;
    var left = false;
    var right = false;
    // 给定起点并定义坐标
    var x = 1;
    var y = 1;
    arr[x][y] = 1;
    right = true;
    for (let i = 2; i <= Math.pow(n, 2); i++) {
        if (right) {
            if (arr[x][y+1] !== 0) {
                right = false;
                down = true;
                i--;
                continue;
            } else {
                y = y + 1;
                arr[x][y] = i;
            }
        }
        else if (down) {
            if (arr[x+1][y] !== 0) {
                down = false;
                left = true;
                i--;
                continue;
            } else {
                x = x + 1;
                arr[x][y] = i;
            }
        }
        else if (left) {
            if (arr[x][y-1] !== 0) {
                left = false;
                up = true;
                i--;
                continue;
            } else {
                y = y - 1;
                arr[x][y] = i;
            }
        }
        else if (up) {
            if (arr[x-1][y] !== 0) {
                up = false;
                right = true;
                i--;
                continue;
            } else {
                x = x - 1;
                arr[x][y] = i;
            }
        }
    }
    var ans = arr.slice(1, arr.length - 1).map(x => x.slice(1, x.length - 1));
    return ans;
};
```
代码先放上，解释稍后补。（如果有必要的话）
去学习大佬们的做法了。😂
