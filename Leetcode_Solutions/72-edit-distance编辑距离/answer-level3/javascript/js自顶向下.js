```
var minDistance = function (word1, word2) {
    var row = word1.length,
        col = word2.length;
    if (!row || !col) return row+col;
    //初始化
    var dp = new Array(row + 1).fill(0).map(() => new Array(col + 1).fill(0));
    for (var i = 0; i <= row; i++) {
        dp[i][0] = i;
    }
    for (var j = 0; j <= col; j++) {
        dp[0][j] = j;
    }
    //dp
    for (var i = 1; i < dp.length; i++) {
        for (var j = 1; j < dp[0].length; j++) {
            if (word1[i - 1] === word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            }
        }
    }
    return dp[row][col]
};
```
