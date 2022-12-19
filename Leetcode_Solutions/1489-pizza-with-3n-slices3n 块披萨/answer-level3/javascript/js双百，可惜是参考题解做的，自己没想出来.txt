### 解题思路
![image.png](https://pic.leetcode-cn.com/9c36c315fb14cda8e3a905cac851292bcb78b059acb7b6ea3026c19eff93229d-image.png)

学习了，二维的dp。

### 代码

```javascript
/**
 * @param {number[]} slices
 * @return {number}
 */
var maxSizeSlices = function(slices) {

    const dpMeth = arr => {
        let dp = [];
        const len = arr.length;
        const round = (len + 1) / 3;
        for (let i = 0; i <= len; i++) {
            dp.push(new Int32Array(round + 1));
        }

        dp[1][1] = arr[0];
        for (let i = 1; i <= len; i++) {
            for (let j = 1; j <= round; j++) {
                dp[i][j] = Math.max((i >= 2 ? dp[i - 2][j - 1] : 0) + arr[i - 1], dp[i - 1][j]);
            }
        }
        return dp[len][round];
    }
    return Math.max(dpMeth(slices.slice(1)), dpMeth(slices.slice(0, slices.length - 1)));
};
```