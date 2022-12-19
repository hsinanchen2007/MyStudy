- dp[i][j]：表示从第i个到第j个角所形成的三角形的最小面积
- 状态转换方程 dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[k] * A[j])
```
var minScoreTriangulation = function(A) {
  let len = A.length;
  let dp = Array.from({length: len}, () => new Array(len).fill(10000000));
  for (let i = 0; i < len; ++i) {
    dp[i][i+1] = 0;
  }
  for (let length = 2; length < len; ++length) {
    for (let left = 0, end = len - 2; left < end; ++left) {
      for (let mid = left +1; mid <= end; ++mid) {
        dp[left][left+length] = Math.min(dp[left][left+length], A[left]*A[mid]*A[left+length] + dp[left][mid] + dp[mid][left+length])
      }
    }
  }
  return dp[0][len - 1];
};
```

