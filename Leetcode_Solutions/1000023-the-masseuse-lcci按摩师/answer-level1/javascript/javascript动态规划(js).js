动态规划

思路和算法

定义 dp[i][0]dp[i][0] 表示考虑前 ii 个预约，第 ii 个预约不接的最长预约时间，dp[i][1]dp[i][1] 表示考虑前 ii 个预约，第 ii 个预约接的最长预约时间。

从前往后计算 dpdp 值，假设我们已经计算出前 i-1i−1 个 dpdp 值，考虑计算 dp[i][0/1]dp[i][0/1] 的答案。

首先考虑 dp[i][0]dp[i][0] 的转移方程，由于这个状态下第 ii 个预约是不接的，所以第 i-1i−1 个预约接或不接都可以，故可以从 dp[i-1][0]dp[i−1][0] 和 dp[i-1][1]dp[i−1][1] 两个状态转移过来，转移方程即为：

dp[i][0]=max(dp[i-1][0],dp[i-1][1])
dp[i][0]=max(dp[i−1][0],dp[i−1][1])

对于 dp[i][1]dp[i][1] ，由于这个状态下第 ii 个预约要接，根据题目要求按摩师不能接受相邻的预约，所以第 i-1i−1 个预约不能接受，故我们只能从 dp[i-1][0]dp[i−1][0] 这个状态转移过来，转移方程即为：

dp[i][1]=dp[i-1][0]+\textit{nums}_i
dp[i][1]=dp[i−1][0]+nums 
i
​	
 

其中 \textit{nums}_inums 
i
​	
  表示第 ii 个预约的时长。

最后答案即为 max(dp[n][0],dp[n][1])max(dp[n][0],dp[n][1]) ，其中 nn 表示预约的个数。

再回来看转移方程，我们发现计算 dp[i][0/1]dp[i][0/1] 时，只与前一个状态 dp[i-1][0/1]dp[i−1][0/1] 有关，所以我们可以不用开数组，只用两个变量 dp_0dp 
0
​	
 ，dp_1dp 
1
​	
  分别存储 dp[i-1][0]dp[i−1][0] 和 dp[i-1][1]dp[i−1][1] 的答案，然后去转移更新答案即可。



```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function(nums) {
    const len = nums.length;
    if (len === 0) {
        return 0;
    }

    let dp_i_0 = 0;
    let dp_i_1 = nums[0];
    for (let i = 1; i < len; i++) {
        const temp_0 = Math.max(dp_i_0, dp_i_1);
        const temp_1 = dp_i_0 + nums[i];
        dp_i_0 = temp_0;
        dp_i_1 = temp_1;
    }
    return Math.max(dp_i_0, dp_i_1);
};
```