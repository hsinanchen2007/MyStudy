

### [695\. 岛屿的最大面积(Max Area of Island)](https://leetcode-cn.com/problems/max-area-of-island/)

Difficulty: **中等**


给定一个包含了一些 0 和 1的非空二维数组 `grid` , 一个 **岛屿** 是由四个方向 (水平或垂直) 的 `1` (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)

**示例 1:**

```
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
```

对于上面这个给定矩阵应返回 `6`。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。

**示例 2:**

```
[[0,0,0,0,0,0,0,0]]
```

对于上面这个给定的矩阵, 返回 `0`。

**注意:** 给定的矩阵`grid` 的长度和宽度都不超过 50。


#### Solution

**解题思路：**

1. 要找出最大岛屿的面积，那肯定需要遍历所有的岛屿，这里可以选深度优先或者广度优先来进行遍历
2. 当遍历到当前坐标为 `1` 时，我们同时需要对当前左边上下左右四个方向进行判断，判断其是否为是岛屿
3. 为了防止岛屿间的重复遍历，每当遍历到当前坐标为 `1` 后，就将其置为 `0`

**代码**
Language: **JavaScript**

##### 解法一：深度优先遍历（DFS）

```javascript
​/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
    let row = grid.length, col = grid[0].length;
    function dfs (x, y) {
        if (x < 0 || x >= row || y < 0 || y >= col || grid[x][y] === 0) return 0;
        grid[x][y] = 0;
        let ans = 1, dx = [-1, 1, 0, 0], dy = [0, 0, 1, -1];
        for (let i = 0; i < dx.length; i++) {
            ans += dfs(x + dx[i], y + dy[i]);
        }
        return ans;
    }
    let res = 0;
    for (let i = 0; i < row; i++) {
        for (let j = 0; j < col; j++) {
            res = Math.max(res, dfs(i, j));
        }
    }
    return res;
};

```

**复杂度分析**

- **时间复杂度**：`O(M * N)`。`M` 是网格中的行数，`N` 是列数。每个网格最多访问一次。

- **空间复杂度**：`O(M * N)`。递归的深度最大可能是整个网格的大小，因此最大可能使用 `O(M * N)` 的栈空间。

##### 解法二：广度优先遍历（BFS）

```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
    let ans = 0, row = grid.length, col = grid[0].length;
    let dx = [1, -1, 0, 0], dy = [0, 0, 1, -1];
    for (let i = 0; i < row; i++) {
        for (let j = 0; j < col; j++) {
            if (grid[i][j] === 0) continue;
            let queue = [[i, j]], curr = 0;
            while (queue.length > 0) {
                let [x, y] = queue.shift();
                if (x < 0 || x >= row || y < 0 || y >= col || grid[x][y] === 0) continue;
                ++curr;
                grid[x][y] = 0;
                for (let k = 0; k < dx.length; k++) {
                    queue.push([x + dx[k], y + dy[k]]);
                }
            }
            ans = Math.max(ans, curr);
        }
    }
    return ans;
};
```

**复杂度分析**

- **时间复杂度**：`O(M * N)`。`M` 是网格中的行数，`N` 是列数。每个网格最多访问一次。

- **空间复杂度**：`O(M * N)`。队列中最多会存放所有的土地。
  