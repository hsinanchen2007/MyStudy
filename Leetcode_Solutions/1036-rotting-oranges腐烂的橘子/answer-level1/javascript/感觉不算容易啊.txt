### 解题思路
![image.png](https://pic.leetcode-cn.com/aa2b1a7b81cb592a9ca4cb8923e45f3cc0864e6d9641b1678867144c94537014-image.png)

一开始思路都是直接在grid上修修改改，1改成2，感觉越改越乱，后来耐不住看了题解，看到了“队列”两字，幡然醒悟。队列的应用方式和二叉树层级序列化那个算法有些类似。

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function (grid) {
    let que = [],
        curr = [],
        colLen = grid.length,
        rowLen = grid[0].length,
        allRotted = true,
        queLen = 0,
        minCnt = 0;

    for (let i = 0; i < colLen; i++) {
        for (let j = 0; j < rowLen; j++) {
            if (grid[i][j] === 2) {
                que.push([i, j]);
            } else if (grid[i][j] === 1) {
                allRotted = false;
            }

        }
    }
    if (allRotted) return 0;

    //rotting
    while (que.length > 0) {
        queLen = que.length;
        // continueFlag = false;
        for (let i = 0; i < queLen; i++) {
            curr = que.shift();
            for (let i = curr[0] - 1; i >= 0 && i >= curr[0] - 1; i--) {
                if (grid[i][curr[1]] === 1) que.push([i, curr[1]]); grid[i][curr[1]] = 2;
            }
            for (let i = curr[0] + 1; i <= curr[0] + 1 && i < colLen; i++) {
                if (grid[i][curr[1]] === 1) que.push([i, curr[1]]); grid[i][curr[1]] = 2;
            }
            for (let i = curr[1] - 1; i >= 0 && i >= curr[1] - 1; i--) {
                if (grid[curr[0]][i] === 1) que.push([curr[0], i]); grid[curr[0]][i] = 2;
            }
            for (let i = curr[1] + 1; i <= curr[1] + 1 && i < rowLen; i++) {
                if (grid[curr[0]][i] === 1) que.push([curr[0], i]); grid[curr[0]][i] = 2;
            }
        }
        minCnt++;
    }
    for (let i = 0; i < colLen; i++) {
        for (let j = 0; j < rowLen; j++) {
            if (grid[i][j] === 1) {
                return -1;
            }
        }
    }
    return minCnt - 1;
};
```