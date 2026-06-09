#### 解题思路
1. 遍历一遍，记录已腐烂的入队列， 并且记录新鲜的fresh
2. 取出队列中的点，且用四联通将周围的点变腐烂，
    + 变腐烂的点 入新的队列next, 表示下一层
    + 且将fresh自减
    + 此层队列空了的话，minutes++ ,开始遍历下一层
3. 当队列空了，或没新鲜的，完成返回minutes, 记得还要处理有新鲜的要返回-1
#### 代码
```
var orangesRotting = function (grid) {

    let minutes = 0;
    let fresh = 0;
    let queue = [];

    let len_r = grid.length;
    let len_c = grid[0].length;
    //遍历一遍 m*n
    for (let r = 0; r < len_r; r++) {
        for (let c = 0; c < len_c; c++) {
            //新鲜加1
            if (grid[r][c] == 1) fresh++;
            //腐烂的入队列
            if (grid[r][c] == 2) queue.push([r, c]);
        }
    }
    // 没腐烂 或 没新鲜
    while (queue.length != 0 && fresh) {
        //四联通
        let dR = [0, -1, 0, 1];
        let dC = [-1, 0, 1, 0];
        let next = [];
        // bfs
        while (queue.length != 0) {
            let current = queue.pop();
            //上下左右扫一遍
            for (let i = 0; i < dR.length; i++) {
                let nR = current[0] + dR[i];
                let nC = current[1] + dC[i];
                // 边界
                if (nR >= 0 && nC >= 0 && nR < len_r && nC < len_c) {
                    //变腐烂且入队列,新鲜减1
                    if (grid[nR][nC] == 1) {
                        grid[nR][nC] = 2;
                        next.push([nR, nC]);
                        fresh--;
                    }
                }
            }
        }
        minutes++;
        //下一层
        queue = next;
    }

    return fresh == 0 ? minutes : -1;
};
```
