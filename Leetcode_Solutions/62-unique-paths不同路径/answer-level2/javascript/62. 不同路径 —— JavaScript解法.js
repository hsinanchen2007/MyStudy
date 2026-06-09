// ## 题目剖析🧐

// ### 题目描述📄
// > 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
// 问总共有多少条不同的路径？

// ### 思路分析💡

// 对于 ``m x n`` 大小的网格
// - 当 ``m === 0`` 或者 ``n === 0`` 时，结果为 ``0``
// - 当 ``m === 1 且 n >= 1`` 或 ``n === 1 且 m >= 1`` 时，结果为 ``1``
// - 当 ``m > 1 且 n > 1`` 时，结果为 ``ans[n - 1][m] + ans[n][m - 1]``

// 根据上面的思路我们可以得出如下代码👇
// ```javascript
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
    if (m < 1 || n < 1) {
        return 0
    }
    const ans = []
    for (let i = 0; i < n; i++) {
        ans[i] = []
        for (let j = 0; j < m; j++) {
            if (i === 0 || j === 0) {
                ans[i][j] = 1
            } else {
                ans[i][j] = ans[i - 1][j] + ans[i][j - 1]
            }
        }
    }
    return ans[n - 1][m - 1]
};
// ```
// 不过细心的朋友可能发现了，最后得出结果其实只需要 ``ans[i - 1][j]`` 和 ``ans[i][j - 1]`` 这两个变量，通过这点我们可以来优化下它的空间复杂度。

// ## 示例代码🌰

// ```javascript
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
    if (m < 1 || n < 1) {
        return 0
    }
    const ans = []
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (i === 0 || j === 0) {
                ans[j] = 1
            } else {
                ans[j] += ans[j - 1]
            }
        }
    }
    return ans[m - 1]
};
// ```