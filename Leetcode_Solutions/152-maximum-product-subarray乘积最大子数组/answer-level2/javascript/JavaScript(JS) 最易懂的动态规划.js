### 解题思路
考虑到负负得正的情况，需要记录从 0 到 i 位的乘积的最大值和最小值，
DP[i][0] 表示从 0 至 i 所有乘积中的最大值，DP[i][1] 表示从 0 至 i 所有乘积中的最小值。
DP 方程也需要分情况讨论，DP 方程：DP[i+1] = DP[i] * a[i+1]。
状态还可以进一步压缩，由于最后只返回 max，所以可以不要把每一步的 DP[i] 都保留。(见方法三)

### 代码
方法一：最易懂
```javascript
var maxProduct = function (nums) {
    if (!nums.length) return null
    let state = [], max = nums[0];
    for (let i = 0; i < nums.length; i++) {
        state[i] = [0, 0];
    }

    state[0][0] = nums[0]; // 从 0 至 0 处的最大值
    state[0][1] = nums[0]; // 从 0 至 0 处的最小值

    for (let i = 1; i < nums.length; i++) {
        if (nums[i] >= 0) {
            state[i][0] = Math.max(state[i - 1][0] * nums[i], nums[i]);
            state[i][1] = Math.min(state[i - 1][1] * nums[i], nums[i]);
        } else {
            state[i][0] = Math.max(state[i - 1][1] * nums[i], nums[i]);
            state[i][1] = Math.min(state[i - 1][0] * nums[i], nums[i]);
        }
        if (max < state[i][0]) max = state[i][0]
    };
    return max
}
```

方法二：在一的基础上，合并代码

```javascript
var maxProduct = function (nums) {
    if (!nums.length) return null
    let state = [], max = nums[0];
    for (let i = 0; i < nums.length; i++) {
        state[i] = [];
    }

    state[0][0] = nums[0]; // 从 0 至 0 处的最大值
    state[0][1] = nums[0]; // 从 0 至 0 处的最小值

    for (let i = 1; i < nums.length; i++) {
        state[i][0] = Math.max(state[i - 1][0] * nums[i], nums[i],state[i - 1][1] * nums[i]);
        state[i][1] = Math.min(state[i - 1][1] * nums[i], nums[i],state[i - 1][0] * nums[i]);
        if (max < state[i][0]) max = state[i][0]
    };
    return max
}
```
方法三：极致优化版：
```javascript
var maxProduct = function (nums) {
    if (!nums.length) return null
    let [max, curMax, curMin] = [nums[0], nums[0], nums[0]]

    for (let i = 1; i < nums.length; i++) {
        [curMax, curMin] = [curMax * nums[i], curMin * nums[i]];
        [curMax, curMin] = [Math.max(curMax, curMin, nums[i]), Math.min(curMax, curMin, nums[i])];
        if (max < curMax) max = curMax;
    };
    return max
}
```
