
## 题目分析

题目提到了数字的数位之和，这个利用取余运算即可，并将其单独封装函数。代码如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
// 原文地址：https://xxoo521.com/2020-02-20-moving-count/

/**
 * 计算数字 n 的数位之和
 * @param {number} n
 * @return {number}
 */
function bitSum(n) {
    let res = 0;
    while (n) {
        res = res + (n % 10);
        n = Math.floor(n / 10);
    }
    return res;
}
```

**要注意的是：能满足数位之和的要求的坐标，不一定能达到**。因为题目提到了机器人的移动是每次可以向上下左右 4 个方向移动一格，并且开始的坐标是`(0, 0)`。

例如当 m=36，n=15，k=9 时，由于只能向合法坐标移动 1 格，从`(18,0)`并不能到达`(20, 0)`，即使`(20, 0)`满足数位之和的条件。

这就需要使用深度优先遍历（DFS）或者广度优先遍历（BFS），而不是直接检查每个元素。

## 解法 1: 广度优先遍历（推荐）

和普通 BFS 相比，有两点不同：

-   需要调用 bitSum 来检查数位之和
-   **因为从左上角开始遍历，因此只需要遍历「右」和「下」这两个方向**

代码如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
// 原文地址：https://xxoo521.com/2020-02-20-moving-count/
/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var movingCount = function(m, n, k) {
    let res = 0;
    const directions = [
        [1, 0],
        [0, 1]
    ];
    const queue = [[0, 0]];
    const visited = {
        "0-0": true
    }; // 标记 (x,y) 是否被访问过

    while (queue.length) {
        const [x, y] = queue.shift();
        //  (x, y) 的数位之和不符合要求
        // 题目要求节点每次只能走1格，所以无法从当前坐标继续出发
        if (bitSum(x) + bitSum(y) > k) {
            continue;
        }
        ++res;

        for (const direction of directions) {
            const newx = direction[0] + x;
            const newy = direction[1] + y;
            if (
                !visited[`${newx}-${newy}`] &&
                newx >= 0 &&
                newy >= 0 &&
                newx < m &&
                newy < n
            ) {
                queue.push([newx, newy]);
                visited[`${newx}-${newy}`] = true;
            }
        }
    }

    return res;
};
```

时间复杂度是$O(N)$，空间复杂度是$O(N)$。

## 解法 2: 深度优先遍历

DFS 不如 BFS，除了递归调用外，还要尝试 4 个方向（BFS 只要 2 个）。代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
// 原文地址：https://xxoo521.com/2020-02-20-moving-count/
/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var movingCount = function(m, n, k) {
    let res = 0;
    const directions = [
        [-1, 0],
        [1, 0],
        [0, -1],
        [0, 1]
    ];
    const visited = {};
    dfs(0, 0);
    return res;

    function dfs(x, y) {
        visited[`${x}-${y}`] = true;
        if (bitSum(x) + bitSum(y) > k) {
            return;
        }
        ++res;

        for (const direction of directions) {
            const newx = direction[0] + x;
            const newy = direction[1] + y;
            if (
                !visited[`${newx}-${newy}`] &&
                newx >= 0 &&
                newy >= 0 &&
                newx < m &&
                newy < n
            ) {
                dfs(newx, newy);
            }
        }
    }
};
```

时间复杂度是$O(N)$，空间复杂度是$O(N)$。

## 更多资料

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
