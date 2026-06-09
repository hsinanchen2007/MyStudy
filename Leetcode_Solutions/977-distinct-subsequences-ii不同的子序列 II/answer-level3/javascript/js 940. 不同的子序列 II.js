子序列的定义：从原序列中任意选择一些项，保持相对序列不变，得到的就是原序列的子序列

方程状态定义，dp[i]就为到索引为i的文字为止，能生成的子序列的个数
例如：初始状态dp[0] = dp[-1] * 2 + 1; // 非法的值赋为0，所以dp[0] 为1
状态方程推断
如果当前的文字没有出现过，那么当前位置能新生成子序列的个数就为，前一位的个数 + 自己，总数就为 前一位的个数 + 前一位的个数 + 1
dp[I]  = dp[i-1] * 2 - 1;
如果当前的文字出现过，自己就不能加进去了，新生成的就为 前一位的个数 + 前一位的个数 - 重复的个数
此时重复的个数是多少呢，是这个文字前一次的位置的【除了自己以外的新生成】，假设这个文字当前的位置是i，上一次位置是j，那么重复的个数为dp[j - 1]


```
/**
 * @param {string} S
 * @return {number}
 */
var distinctSubseqII = function (S) {
  const dp = [];
  const count = {};
  const MOD = 1000000007;
  let length = S.length;
  for (let i = 0; i < length; i++) {
    const preDp = dp[i - 1] || 0;
    if (typeof count[S[i]] === 'undefined') {
      dp[i] = preDp * 2 + 1;
    } else {
      const prePositionDp = dp[count[S[i]] - 1] || 0;
      dp[i] = preDp * 2 - prePositionDp;
      if (dp[i] < 0) {
        dp[i] += MOD;
      }
    }
    dp[i] %= MOD;
    count[S[i]] = i;
  }
  return dp[S.length - 1];
};
```
