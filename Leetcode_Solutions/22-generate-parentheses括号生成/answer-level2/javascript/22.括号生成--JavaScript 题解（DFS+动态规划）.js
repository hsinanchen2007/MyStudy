# dfs解法
```
var generateParenthesis = function (n) {
    var arr = []
    dfs(n, n, '', arr)
    return arr
};

function dfs(left, right, res, arr) {
    // 左右括号都没有
    if (!left && !right) {
        arr.push(res)
        return
    }
    // 还有左括号可以拼接
    if (left) dfs(left - 1, right, res + '(', arr)
    // 右括号数量多于左括号，可以拼接
    if (right > left) dfs(left, right - 1, res + ')', arr)
}
```

# 动态规划
```
var generateParenthesis = function (n) {
    var dp = []
    dp[0] = ['']
    for (var i = 1; i <= n; i++) {
        for (var j = 0; j < i; j++) {
            var temp1 = dp[j]
            var temp2 = dp[i - j - 1]
            for (var str1 of temp1) {
                for (var str2 of temp2) {
                    if(!dp[i]) dp[i] = []
                    dp[i].push('(' + str1 + ')' + str2)
                }
            }
        }
    }
    return dp[n]
};
```

