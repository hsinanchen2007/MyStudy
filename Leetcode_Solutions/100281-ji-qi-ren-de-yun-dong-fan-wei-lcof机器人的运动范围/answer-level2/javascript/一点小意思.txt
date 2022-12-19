### 解题思路

#### 这两天看动态规划然后以看题目就想到的，也算是昨天刷题有点用吧，注释很清楚，可以看看 

### 代码

```javascript
/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var movingCount = function (m, n, k) {
    // 存储是否能够移动位置
    let dp = Array.from(new Array(m), () => new Array(n).fill(false));
    // 起点一定是可以到达的
    dp[0][0] = true;
    // x坐标
    for (let i = 0; i < m; i++) {
        // 第一个坐标的和
        let firstSum = i < 10 ? i : Math.floor(i / 10) + i % 10;
        // 横坐标大于k的话 后面都不用走了 因为会有隔断
        if (firstSum > k) {
            break;
        }
        // 不大于k的话 第一行是肯定得行的
        dp[i][0] = true;
        for (let j = 1; j < n; j++) {
            // 第二个坐标的和
            let lastSum = j < 10 ? j : Math.floor(j / 10) + j % 10;
            // 坐标位数和
            let sum = firstSum + lastSum;
            // 如果位数和大于目标值也得往上走 有可能左边走的通
            if (sum <= k) {
                // 如果第一列的话 不得行不往上走
                if (i == 0 && !dp[i][j - 1]) {
                    break;
                }
                // 如果第一列的话 判断下即可
                if (i == 0 && dp[i][j - 1]) {
                    dp[i][j] = true;
                }
                // 不是第一列判断左下是否有一个可通的就行 我们是往右，然后往上走的 
                if (i > 0 && (dp[i - 1][j] || dp[i][j - 1])) {
                    dp[i][j] = true;
                }
            }

        }
    }
    let countSum = 0;
    dp.forEach(item => {
        item.forEach(item1 => {
            if (item1) countSum += 1;
        })
    })
    return countSum;


};
```