> 状态转移方程：dp[i] = dp[i - 1].forEach + currentChar

### 解法

```
var letterCombinations = function(digits) {
    if (!digits) return [];
    var map = {
        2: 'abc',
        3: 'def',
        4: 'ghi',
        5: 'jkl',
        6: 'mno',
        7: 'pqrs',
        8: 'tuv',
        9: 'wxyz',
    };
    var dp = [];
    for (var i = 0; i < digits.length; i++) {
        var cur = map[digits[i]];
        if (i === 0) {
            dp[0] = Array.from(cur);
            continue;
        }
        dp[i] = [];
        for (var j = 0; j < cur.length; j++) {
            dp[i - 1].forEach((item) => dp[i].push(item + cur[j]));
        }
    }
    return dp[digits.length - 1];
};
```

### 优化
dp数组存储基本可以转换成两个变量来存储状态，节约内存空间，因此有：

```
var letterCombinations = function(digits) {
    if (!digits) return [];
    var map = {
        2: 'abc',
        3: 'def',
        4: 'ghi',
        5: 'jkl',
        6: 'mno',
        7: 'pqrs',
        8: 'tuv',
        9: 'wxyz',
    };
    var dp;
    var prev;
    for (var i = 0; i < digits.length; i++) {
        var cur = map[digits[i]];
        if (i === 0) {
            dp = Array.from(cur);
            continue;
        }
        prev = dp;
        dp = [];
        for (var j = 0; j < cur.length; j++) {
            prev.forEach((item) => dp.push(item + cur[j]));
        }
    }
    return dp;
};
```
