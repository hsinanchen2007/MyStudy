### 解题思路
既然 [84. 柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/) 中使用单调栈能求出一维数组中的最大矩形，那么我们将二维数组转化为一维数组：

用 dp[i] 表示从当前位置开始，该列向上的最多连续的 '1' 的个数。

对于每一行，使用动态规划求出该行的 dp，再求解该行的 maxArea 并更新结果。

### 代码

```javascript
/**
 * @param {character[][]} matrix
 * @return {number}
 */
const maxArea = (heights) => {
    const stack = [];
    let ans = 0;
    heights.unshift(0);
    heights.push(0);
    for (let i = 0; i < heights.length; ++i) {
        while (stack.length && heights[stack[stack.length-1]] > heights[i]) {
            const currentHeight = stack.pop();
            const right = i - 1, left = stack[stack.length-1] + 1;
            ans = Math.max(ans, (right-left+1)*heights[currentHeight])     
        }
        stack.push(i);
    }
    return ans;
}
var maximalRectangle = function(matrix) {
    let res = 0;
    if (!matrix.length) return res;
    const dp = [];
    for (let i = 0; i < matrix[0].length; ++i) {
        dp.push(0);
    }
    for (let i = 0; i < matrix.length; ++i) {
        for (let j = 0; j < matrix[0].length; ++j) {
            dp[j] = matrix[i][j] === '1' ? dp[j] + 1 : 0;
        }
        res = Math.max(res, maxArea(dp.slice()));
    }
    return res;
};
```

### 复杂度
- 时间复杂度 O(MN)
- 空间复杂度 O(M)