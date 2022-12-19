- dp[i][j] = [max, result] arr[i]到arr[j]的最大值为max arr[i]到arr[j]构成的树的最大结果为result
- 递推公式dp[i][j][1]代表节点从i到j所能构成的非叶节点的最小和
- dp[i][j][1] = Math.min(dp[i][j][1],dp[i][k][1] + dp[k+1][j][1] + dp[i][k][0] * dp[k+1][j][0]);
```
var mctFromLeafValues = function (arr) {
  let len = arr.length;
  let dp = Array.from({ length: len }, () => Array.from({ length: len }, () => [0, 2147483648]));
  arr.forEach((el, i) => {
    dp[i][i][0] = el
    dp[i][i][1] = 0
  });
  let dfs = function (left, right) {
    if (dp[left][right][0]) return dp[left][right][0]
    for (let i = left; i < right; ++i) {
      dp[left][right][1] = Math.min(dp[left][right][1], dfs(left, i) * dfs(i + 1, right) + dp[left][i][1] + dp[i + 1][right][1])
    }
    dp[left][right][0] = Math.max(dp[left][left][0], dp[left + 1][right][0])
    return dp[left][right][0];
  }
  dfs(0, len - 1)
  return dp[0][len - 1][1]
};
```
