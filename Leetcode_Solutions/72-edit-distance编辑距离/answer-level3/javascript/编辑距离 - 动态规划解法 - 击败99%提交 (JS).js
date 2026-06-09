### 思路

这道题直观的想法是使用回溯的方法来做，从头开始处理`word1`，每一个字符我们都有添加、删除、替换的选项在，即每一步都要走到底再返回上一步继续执行，执行时会超时。

当我们需要处理`horse`与`ros`的编辑距离时，我们很容易发现如果两边的字符都比较短，处理速度就会很快，例如`ho`与`ro`的编辑距离，一眼就能看出是`1`。这是一个非常适合动态规划的题目，其解题的思路与[10. Regular Expression Matching](http://blog.leanote.com/post/y.ruibin09@gmail.com/LeetCode-10)非常相似。

#### 状态
对于动态规划，我们需要定义一个状态`dp`。我们需要把题目切分成更小的问题来处理，我们可以定义一个二维数组，`dp[i][j]`代表`word1`的前`i`位字符与`word2`的前`j`位字符的编辑距离。

#### 转移方程
我们接着需要考虑的是在循环中如何确定`dp[i][j]`的值，假设已知`dp[i][j]`之前的状态，也知道`word1[i]`与`word2[j]`的值，那么`dp[i][j]`的值有以下两种情况：

* 若`word1[i] == word2[j]`，此时`dp[i][j]`的编辑次数等于`dp[i-1][j-1]`的编辑次数。
* 若`word1[i] != word2[j]`，我们可以对`word1`进行添加、删除以及替换的操作，此时`dp[i][j]`的值有下面三种情况:
  * `word1`的前`i`位与`word2`的前`j - 1`位的编辑次数, 加上添加`word2`的第`j`位字符于 `word2`的操作，即`dp[i][j - 1] + 1`。
  * `word1`的前`i - 1`位与`word2`的前`j`位的编辑次数, 加上将`word1`的第`i`位字符删除的操作，即`dp[i - 1][j] + 1`。
  * `word1`的前`i - 1`位与`word2`的前`j - 1`位的编辑次数，加上将`i`位字符替换成`j`位字符的操作，即`dp[i - 1][j - 1] + 1`。
```JavaScript []
if (word1[i] === word2[j]) {
    dp[i][j] = dp[i - 1][j - 1];
} else {
    dp[i][j] = Math.min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1;
}
```

#### 初始化
我们留意到，在上述的状态转移方程中，我们在确定`dp[i][j]`的值时，依赖于上一行或者上一列的数据，因此在初始化时，我们可以在`word1`以及`word2`前面添加一位空格，并且初始化第一行以及第一列，由于第一行及第一列都是空格，我们初始化值时，编辑次数即为另一个字符的非空格字符数。
```JavaScript []
let str1 = ' ' + word1;
let str2 = ' ' + word2;
const n = str1.length, m = str2.length;
let dp = [...new Array(n)].map(() => new Array(m));
for (let i = 0; i < n; i++) {
    dp[i][0] = i;
}
for (let j = 0; j < m; j++) {
    dp[0][j] = j;
}
```
### 完整题解
    执行用时 :80 ms, 在所有 javascript 提交中击败了99.09%的用户
    内存消耗 :38.2 MB, 在所有 javascript 提交中击败了93.10%的用户
```JavaScript []
var minDistance = function (word1, word2) {
    // 在字符串前添加空格，方便初始化 dp 的第一行及第一列
    let str1 = ' ' + word1;
    let str2 = ' ' + word2;

    const n = str1.length, m = str2.length;
    // 若字符间有一个为0，直接返回另一字符的长度，加上此判断可以快 4ms。
    if (n * m === 0) {
        return n + m;
    }
    // 初始化 dp 为 n 行，m 列的二维数组。
    let dp = [...new Array(n)].map(() => new Array(m));
    // 初始化 dp 第一列的编辑次数，如 ' ' 需要 3 次编辑才能变成 ' xxx'。
    for (let i = 0; i < n; i++) {
        dp[i][0] = i;
    }
    // 初始化 dp 第一行的编辑次数，如 ' xxx' 需要经过 3 次编辑才能变成 ' '。
    for (let j = 0; j < m; j++) {
        dp[0][j] = j;
    }

    for (let i = 1; i < n; i++) {
        for (let j = 1; j < m; j++) {
            // 若 str1 的第 i 位可以匹配 str2 的第 j 位，那么其编辑次数就等于
            // str1 的前 i - 1 位 与 str2 的前 j - 1 位的编辑次数。
            if (str1[i] === str2[j]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // 若 str1 的第 i 位不匹配 str2 的第 j 位，那么其编辑次数有三种情况:
                // 1. str1 的前 i 位与 str2 的前 j - 1 位的编辑次数, 加上添加 str2 的第 j 位字符于 str1 的操作，即 dp[i][j - 1] + 1
                // 2. str1 的前 i - 1 位与 str2 的前 j 位的编辑次数, 加上将 str1 的第 i 位字符删除的操作，即 dp[i - 1][j] + 1
                // 3. str1 的前 i - 1 位与 str2 的前 j - 1位的编辑次数，加上将 i 位字符替换成 j 位字符的操作，即 dp[i - 1][j - 1] + 1
                dp[i][j] = Math.min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1;
            }
        }
    }

    return dp[n - 1][m - 1];
};
```