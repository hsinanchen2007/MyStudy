### 解题思路
1. 使用递归
2. 加了缓存的递归
3. 动态规划，自顶向下递推
4. 动态规划，自底向上递推，需要二维空间
5. 一维DP, O(n)空间复杂度

### 代码

```javascript
/**
 * @param {number[][]} triangle
 * @return {number}
 */
// 方法1：递归（超时）
// 自顶向下
var minimumTotal1 = function(triangle) {
    const res = []
    const n = triangle.length
    return reversion(0, 0, triangle)
}
function reversion(i, j, triangle) {
    if (i >= triangle.length-1) {
        return triangle[i][j]
    }
    const left = reversion(i+1, j, triangle)
    const right = reversion(i+1, j+1, triangle)
    return Math.min(left, right) + triangle[i][j]
}

```

```js
// 方法2：加了缓存的递归
var minimumTotal2 = function(triangle) {
    const res = []
    const n = triangle.length
    const memo = new Array(n).fill().map(() => [])
    return reversionByMemo(0, 0, triangle, memo)
}
function reversionByMemo(i, j, triangle, memo) {
    if (i >= triangle.length-1) {
        return triangle[i][j]
    }
    if (memo[i][j]) return memo[i][j]
    const left = reversionByMemo(i+1, j, triangle, memo)
    const right = reversionByMemo(i+1, j+1, triangle, memo)
    memo[i][j] = Math.min(left, right) + triangle[i][j]
    return memo[i][j]
}

```

```js
// 方法3：动态规划，自顶向下递推
// 重复子问题：某个元素(i,j)代表的最小路径和，都为(i-1,j)和(i-1, j-1)的最小路径和中的最小者，再加上本身元素的值
// 但需要判断元素在左右边界的情况，因为左右边界都只有一条路进入
// dp状态：dp[i][j] (i, j)元素代表的最小路径和
// dp方程：dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + dp[i][j]
var minimumTotal3 = function(triangle) {
    const dp = triangle
    for (let i = 1; i < triangle.length; i++) {
        for (let j = 0; j < triangle[i].length; j++) {
            if (j === 0) {
                dp[i][j] += dp[i-1][j]
            } else if (j === triangle[i].length-1) {
                dp[i][j] += dp[i-1][j-1]
            } else {
                dp[i][j] += Math.min(dp[i-1][j], dp[i-1][j-1])
            }
        }
    }
    return Math.min(...dp[triangle.length-1])
}
```

```js
// 方法4：动态规划，自底向上递推
// 重复子问题：某个元素(i,j)代表的最小路径和，都为(i+1,j)和(i+1, j+1)的最小路径和中的最小者，再加上本身元素的值
// dp状态：dp[i][j] (i, j)元素代表的最小路径和
// dp方程：dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + dp[i][j]
var minimumTotal4 = function(triangle) {
    const dp = triangle
    for (let i = triangle.length-2; i >= 0; i--) {
        for (let j = 0; j < triangle[i].length; j++) {
            dp[i][j] += Math.min(dp[i+1][j], dp[i+1][j+1])
        }
    }
    return dp[0][0]
};
```

```js
// 方法5：一维DP, O(n)空间复杂度
// 重复子问题：某个元素(i,j)代表的最小路径和，都为(i+1,j)和(i+1, j+1)的最小路径和中的最小者，再加上本身元素的值
// 因为每次计算都只需要最后一行的数值，所以只需要申请n个空间，n为三角形底边元素的个数，也等于三角形行数
// dp状态：dp[j] 某一行i的j位置元素的最小路径和
// dp方程：dp[j] = min(dp[j], dp[j+1]) + triangle[i][j]
var minimumTotal = function (triangle) {
    const dp = triangle[triangle.length - 1].slice(0)
    for (let i = triangle.length - 2; i >= 0; i--) {
        for (let j = 0; j <= i; j++) {
            dp[j] = Math.min(dp[j], dp[j + 1]) + triangle[i][j]
        }
    }
    return dp[0]
}

```