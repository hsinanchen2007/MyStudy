![Snipaste_2020-04-02_17-00-31.png](https://pic.leetcode-cn.com/ad76d7b112f80af013bc816e7cbff0cb278ef31f093f13df386910efbf0a5aad-Snipaste_2020-04-02_17-00-31.png)
### 解题思路
如果顺序遍历数组，改变了前面元素的状态，也会影响到后续的判断。
本题的关键：**记录元素的状态变化又不影响其他元素的判断**。
由此可以得出两种可行的思路：

### 代码
**方法一**：拷贝数组作为备份，不修改备份，把备份作为判断原数组每个元素的状态的依据。
时间复杂度：O(mn)，空间复杂度：O(mn)
```javascript
var gameOfLife = function (board) {
    if (!board.length) return

    let rows = board.length;
    let cols = board[0].length;

    // 新建并拷贝一份原数组
    let copy = new Array(rows);
    for (let row = 0; row < rows; row++) {
        copy[row] = new Array(cols);
    }

    // let copy = new Array(rows);
    for (let row = 0; row < rows; row++) {
        for (let col = 0; col < cols; col++) {
            copy[row][col] = board[row][col];
        }
    }
    // 遍历每一个格子(细胞)，统计每个格子周围的存活细胞个数
    let neighbors = [0, -1, 1];
    for (let row = 0; row < rows; row++) {
        for (let col = 0; col < cols; col++) {
            // 记录每个格子周围八个格子的存活情况
            let liveBox = 0;
            // 遍历每个格子的周围的八个格子
            for (let i = 0; i < 3; i++) {
                for (let j = 0; j < 3; j++) {
                    if (!i && !j) continue
                    let r = row + neighbors[i];
                    let c = col + neighbors[j];
                    if ((r >= 0 && r < rows) && (c >= 0 && c < cols) && copy[r][c] === 1) {
                        liveBox++;
                    }
                }
            }

            // 通过 liveBox 判断当前格子是否存活
            // 由生变死
            if ((copy[row][col] === 1) && (liveBox < 2 || liveBox > 3)) {
                board[row][col] = 0;
            }
            // 忍术：秽土转生
            if (copy[row][col] === 0 && liveBox === 3) {
                board[row][col] = 1;
            }
        }
    }
};
```

**方法二**：不使用额外空间，用更复杂的状态设计来记录状态变化。
时间复杂度：O(mn)，空间复杂度：O(1)

```javascript
var gameOfLife = function (board) {
    if (!board.length) return

    let rows = board.length;
    let cols = board[0].length;

    // 遍历每一个格子(细胞)，统计每个格子周围的存活细胞个数
    let neighbors = [0, -1, 1];
    for (let row = 0; row < rows; row++) {
        for (let col = 0; col < cols; col++) {
            // 记录每个格子周围八个格子的存活情况
            let liveBox = 0;
            // 遍历每个格子的周围的八个格子
            for (let i = 0; i < 3; i++) {
                for (let j = 0; j < 3; j++) {
                    if (!i && !j) continue
                    let r = row + neighbors[i];
                    let c = col + neighbors[j];
                    // 注意：有些位置为 -1，但是当前它还是活的，这轮过后才死
                    if ((r >= 0 && r < rows) && (c >= 0 && c < cols) && Math.abs(board[r][c]) === 1) {
                        liveBox++;
                    }
                }
            }

            // 通过 liveBox 判断当前格子是否存活
            // 由生变死记为 -1
            if ((board[row][col] === 1) && (liveBox < 2 || liveBox > 3)) {
                board[row][col] = -1;
            }
            // 忍术：秽土转生记为 2
            if (board[row][col] === 0 && liveBox === 3) {
                board[row][col] = 2;
            }
        }
    }

    // 转换状态，2 -> 1，-1 -> 0
    for (let row = 0; row < rows; row++) {
        for (let col = 0; col < cols; col++) {
            board[row][col] = board[row][col] > 0 ? 1 : 0;
        }
    }
};
```
![扫码_搜索联合传播样式-标准色版.png](https://pic.leetcode-cn.com/63c5ca01205e43b180036837eaf12616fd7536efbf258fb816c7868f7b7206be-%E6%89%AB%E7%A0%81_%E6%90%9C%E7%B4%A2%E8%81%94%E5%90%88%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)

