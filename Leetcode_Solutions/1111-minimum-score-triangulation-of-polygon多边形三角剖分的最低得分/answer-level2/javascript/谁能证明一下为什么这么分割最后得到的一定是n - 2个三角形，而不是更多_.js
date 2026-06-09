谁能证明一下为什么这么分割最后得到的一定是n - 2个三角形，而不是更多?
递推倒好像是这样。
3个点构成1个三角形
4个点构成1 + 1个三角形
5个点构成1 + 2 或 1 + 1 + 1 = 3个三角形
6个点构成1 + 3 或 1 + 1 + 2 = 4个三角形
7个点构成1 + 4 或 1 + 1 + 3  或1 + 2 + 2 = 5个三角形
但是如何证明呢？
```
/**
 * 这道题目的关键是:
 * 可以把任何顶点数大于3的凸多边形分解为一个三角形和至多两个凸多边形，并且按这种
 * 方式分割，最后n个顶点得到的一定是n - 2个三角形（我不知道最后得到的一定是n - 2个三角形怎么证明
 * ）。
 * 那么这个就可以dp了
 * @param {number[]} A
 * @return {number}
 */
var minScoreTriangulation = function(A) {
    const len = A.length
    const dp = new Array(len)
    // 因为dp求的是最小值，那么初始化为最大值
    for(let i = 0;i < len;i++) dp[i] = new Array(len).fill(Infinity)
    for(let i = 0;i < len;i++) {
        // 顶点数小于3不能构成三角形，dp中不会有用到顶点数为1的情况。
        //i、j包含顶点数小于2的情况的值都初始化为0,便于后面计算
        dp[i][(i + 1) % len] = 0
    }
    // temp_len + 1代表凸多边形的顶点个数
    // dp先求凸多边形有3个定点的情况，再求有4个顶点的情况下，直至求出有length个顶点的情况
    for(let temp_len = 2;temp_len < len;temp_len++) {
        // 这些顶点中第一个顶点是i，最后一个顶点是j。
        // i和j都有可能为0 ~ (len - 1)（开闭区间）中的任何一个点
        for(let i = 0;i < len;i++) {
            let j = (i + temp_len) % len
            // 虽然是循环的，但可以认为j在i的后面，也就是k永远不可能等于i或j
            for(let k = (i + 1) % len;k !== j;k = (k + 1) % len) {
                dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[k] * A[j])
            }
        }
    }
    return dp[0][len - 1]
};
```
