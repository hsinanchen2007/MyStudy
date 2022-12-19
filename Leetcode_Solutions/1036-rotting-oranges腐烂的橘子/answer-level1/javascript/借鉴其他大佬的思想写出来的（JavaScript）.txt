### 解题思路
1. 遍历grid，将腐烂的坐标和当前次数（0）加入队列中
2. 遍历队列，将队列的第一个出列，并将他所能腐烂的果子的信息（坐标和当前次数）加入队列

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function(grid) {
    let queue = [];
    let res = 0;

    for(let i = 0; i < grid.length; i++) {
        for(let j = 0; j < grid[0].length; j++) {
            if(grid[i][j] === 2) {
                queue.push({
                    i,
                    j,
                    res,
                })
            }
        }
    }
    while(queue.length > 0) {
        let qTop = queue.shift();

        let i = qTop.i;
        let j = qTop.j;

        let top = i >=1 ? grid[i - 1][j] : 0;
        let bot = i < grid.length - 1 ? grid[i + 1][j] : 0;
        let lef = j >=1 ? grid[i][j - 1] : 0;
        let rig = j < grid[0].length - 1 ? grid[i][j + 1] : 0;

        // console.log(i, j, qTop);
        // console.log(top, bot, lef, rig);

        if(qTop.res == res && (top == 1 || bot == 1 || lef == 1 || rig == 1)) {
            res++;
        }
        if(top == 1) {
            grid[i - 1][j] = 2;
            queue.push({
                i: i - 1,
                j,
                res,
            })
        }
        if(bot == 1) {
            grid[i + 1][j] = 2;
            queue.push({
                i: i + 1,
                j,
                res,
            })
        }
        if(lef == 1) {
            grid[i][j - 1] = 2;
            queue.push({
                i,
                j: j - 1,
                res,
            })
        }
        if(rig == 1) {
            grid[i][j + 1] = 2;
            queue.push({
                i,
                j: j + 1,
                res,
            })
        }
    }
    console.log(grid);
    for(let i in grid) {
        if(grid[i].indexOf(1) != -1) {
            return -1;
        }
    }
    return res;
};

```