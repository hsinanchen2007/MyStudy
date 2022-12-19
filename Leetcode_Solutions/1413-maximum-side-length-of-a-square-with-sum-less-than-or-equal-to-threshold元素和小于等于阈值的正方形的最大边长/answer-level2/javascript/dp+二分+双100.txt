- dp[y][x] 表示以mat[0][0]为左上角顶点和以mat[y-1][x-1]为右下角顶点的矩形中每个数和
- dp[0] = new Array(mat[0].length+1).fill(0)
- dp[y][0] = 0
- 则dp[y][x] = dp[y-1][x] + dp[y][x-1] - dp[y-1][x-1] + mat[y-1][x-1]
- 则以mat[y-1][x-1]为右下角顶点的长度mid的正方形中每个数和为
- dp[y][x] + dp[y-mid][x-mid] - dp[y-mid][x] - dp[y][x-mid]
```
var maxSideLength = function(mat, threshold) {
  let _y = mat.length;
  let _x = mat[0].length;
  let dp = new Array(_y + 1);
  dp[0] = new Array(_x+1).fill(0)
  for (let y = 1; y <= _y; ++y) {
    dp[y] = [0]
    for (let x = 1; x <= _x; ++x) {
      dp[y][x] = dp[y-1][x] + dp[y][x-1] - dp[y-1][x-1] +  mat[y-1][x-1]
    }
  }
  let left = 0;
  let right = Math.min(_y, _x);
  while(left < right) {
    let mid = Math.ceil((left + right) / 2);
    let hasRes = false;
    for (let y = mid; y <= _y; ++y) {
      for (let x = mid; x <= _x; ++x) {
        if (dp[y][x] + dp[y-mid][x-mid] - dp[y-mid][x] - dp[y][x-mid] <= threshold) {
          hasRes = true;
          left = mid;
          break;
        }
      }
      if (hasRes) break;
    }
    if (!hasRes) right = mid-1;
  }
  return left;
};
```
