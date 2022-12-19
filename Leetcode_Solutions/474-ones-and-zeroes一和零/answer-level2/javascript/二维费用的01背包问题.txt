- 这是一道裸的“二维费用的01背包问题”
- 背包模型
    - 物品：数组元素
    - 体积：数组元素的长度
    - 价值：二维费用，消耗的0的个数，1的个数
- 然后就是套`01背包问题`的模板

<br/>
```js
var findMaxForm = function(strs, m, n) {
    /*
    二维费用的01背包问题：
    物品：数组元素
    体积：数组元素的长度，
    价值：二维费用，消耗的0的个数，1的个数
    */
    const map = {};
    for (let str of strs) { // 预处理每个物品的费用
        let ones = 0;
        for (let ch of str) {
            if (ch === '1') ones++;
        }
        map[str] = [str.length - ones, ones];
    }
    const N = strs.length;
    const dp = new Array(m + 1);
    for (let i = 0; i < dp.length; i++) dp[i] = new Array(n + 1).fill(0);

    for (let i = 1; i <= N; i++) {
        const [v0, v1] = map[strs[i - 1]];
        for (let j = m; j >= v0; j--) {
            for (let k = n; k >= v1; k--) {
                dp[j][k] = Math.max(dp[j][k], dp[j - v0][k - v1] + 1);
            }
        }
    }
    return dp[m][n];
};
```
