# **官方解法二思路**

根据官方解法二O(1)空间复杂度思路原地修改的js，希望和大家一起交流更简洁高效的代码。

```
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function (board) {
    var neighbors= [[1, 0], [1, -1], [0, -1], [-1, -1], [-1, 0], [-1, 1], [0, 1], [1, 1]];
    var rows = board.length;//board行数
    var cols = board[0].length;//board列数

    //遍历board数组每一个元素即每一个格子里的细胞
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            //对于当前细胞统计其八个相邻位置里的活细胞数量
            let live_neighbors = 0;
            //遍历八个相邻位置的活细胞
            for (let q = 0; q < neighbors.length; q++) {
                //相邻位置的坐标
                r = (i + neighbors[q][0]);
                c = (j + neighbors[q][1]);
                //查看相邻细胞是否存活
                if ((r < rows && r >= 0) && (c < cols && c >= 0) && Math.abs(board[r][c]) === 1) {
                    live_neighbors += 1;//存活邻居数+1
                }
            }
            //规则一或三
            if (board[i][j] === 1 && (live_neighbors < 2 || live_neighbors > 3)) {
                board[i][j] = -1;//过去是活的现在死了
            }
            //规则四
            if (board[i][j] === 0 && live_neighbors === 3) {
                board[i][j] = 2;//过去是死的现在活了
            }
        }
    }
    //遍历 board 得到一次更新后的状态
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (board[i][j] > 0) {
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }
        }
    }

};
```

- 时间复杂度：O(m,n)，其中m,n分别为数组board的行和列;
- 空间复杂度：O(1)，除原数组外只需要常数的空间存放若干变量;

