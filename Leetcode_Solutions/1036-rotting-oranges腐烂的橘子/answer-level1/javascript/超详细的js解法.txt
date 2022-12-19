```
let r = grid.length;
    let c = grid[0].length;
    let queue = [];
    let flag = false;
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            if (grid[i][j] === 2) {
                queue.push([i, j]);    //  由于题目并没有说明总共只有一个烂橘子，所以第一步先找出所有的腐烂橘子作为BFS起点
            } else if (grid[i][j] === 1) {
                flag = true;          // 标记是否有完好的橘子，如果都是坏的，那就不用等它腐烂了，直接返回
            }
        }
    }
    if (!flag) return 0;
    let res = 0;
    let directions = [[0, 1], [0, -1], [-1, 0],[1, 0]];  // 往四个方向腐烂
    while (queue.length) {
        let len = queue.length;
        while (len--) {
            let curr = queue.shift();
            for (let k = 0; k < 4; k++) {
                let nx = curr[0] + directions[k][0];
                let ny = curr[1] + directions[k][1];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (grid[nx][ny] === 1) {            // 遇到新鲜的橘子，将其感染后，加入到下一次遍历中
                    grid[nx][ny] = 2;
                    queue.push([nx, ny]);
                }
            }
        }
        res++;
    }
    let check = grid.some( _ => _.some(item => item === 1)); // 检测遍历完是否还有完好的橘子
    if (check) return -1;
    return res - 1;      // 最后一次列表中都没有可烂的橘子了，需要减一分钟
```
