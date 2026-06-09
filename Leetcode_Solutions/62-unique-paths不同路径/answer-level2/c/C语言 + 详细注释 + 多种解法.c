太懒就不画图了，大家可以参考其他优秀带图答案的图，本题解重在注释较为详细。

思路比较简单，设dp[i][j]的值为走到位置[i][j]的路径数
由于只能从左上往右下走，行走方式有两种：向下一步、向右一步。那么，
dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
即走到位置[i][j]的路径数 = 走到其**前一个状态**的**两个位置**的路径数之**和**
初值为1，即起始点与终止点位于同一行或者同一列时，只有一条路径数。
来，看代码。

## 一. 递归
递归代码简洁易懂，但是重复计算太多，导致OJ判定超时而无法通过。写出来是为了和思路对照。
```
// 1.0 Recursion implementation
int uniquePaths(int m, int n) {
    // 注意：这里从1开始
    return (m == 1 || n == 1) ? 1 : uniquePaths(m - 1, n) + uniquePaths(n - 1, m);
}
```


## 二. 动态规划
动态规划就用刚才的递推公式（状态转移方程），没有重复计算，时间O(mn)，空间O(mn)
```
// 2.0 Iteratively dynamic programming
int uniquePaths(int m, int n) {
    // 定义二维数组记录结果，dp[i][j]的值表示：走到第i行第j列这个位置的走法的数量
    int dp[m][n];
    // 终点在第一行（各个列）上的路径数量（m是行的长度，所以m为列的数量）
    for (int i = 0; i < m; i++) dp[i][0] = 1;
    // 终点在第一列（各个行）上的路径数量（n是列的长度，所以n是行数）
    for (int j = 0; j < n; j++) dp[0][j] = 1;
    // 循环每一列
    for (int i = 0; i < m; i++)
    // 循环每一行
        for (int j = 0; j < n; j++)
            // 公式
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
    // 返回最后（最右下角）一个元素
    return dp[m - 1][n - 1];
}
```

为了代码行数少的简化写法。
```
// 2.1 Iteratively dynamic programming (等价写法)
int uniquePaths(int m, int n) {
    int dp[m][n];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            dp[i][j] = (i == 0 || j == 0) ? 1 : dp[i - 1][j] + dp[i][j - 1];
    return dp[m - 1][n - 1];
}
```

优化，时间依然O(mn)，空间为O(min(m, n))。因为还是动态规划新手，个人认为这种方法的状态转移方程不太容易想明白，自己想了好久，现在依然不是想的很通，所以尽量想把这块注释写明白，建议想不明白的小伙伴照着这个注释边跟程序边念出来（带入具体数值的念），感觉能好一点。和大家一起熟能生巧吧。也希望能有好的思维方式来理解这个解法的童鞋指点一下。
```
// 2.2 Space optimization
int uniquePaths(int m, int n) {
    int less = (m < n) ? m : n;
    int more = (m > n) ? m : n;
    int dp[less];
    for (int i = 0; i < less; i++) dp[i] = 1;
    // 对于每一列（m是行的长度，所以m为列的数量）
    for (int i = 1; i < more; i++)
        // 循环求每一行的数值，即路径数（n是列的长度，所以n是行数）
        for (int j = 1; j < less; j++)
            // 当前这一列i每一行j的数值 = 前一列（i-1）这一行（j）的数值（左侧） + 当前这一列（i）上一行（j-1）的数值（上面）
            // 本质还是当前dp[i][j] = dp[i - 1][j]（左） + dp[i][j - 1]（上）
            // 只是优化了空间
            dp[j] = dp[j] + dp[j - 1];
    return dp[less - 1];
}
```


## 三. 排列组合数学公式
大家直接看注释吧。公式是
$$C_{m+n-2}^{n-1} = C_{total}^{less}$$
```
// 3.0 Permutation and combination
int uniquePaths(int m, int n) {
    // 注意这里不要定义int，LeetCode会因为m=51，n=9时导致溢出无法通过
    double ans = 1;
    // m是列数，一共就是m-1次向右走（R）；n是行数，一共就是n-1次向下走（D），总操作次数total=(m-1)+(n-1)
    int total = m + n - 2;
    // 如果m>n，就相当于在m-1次向下走操作的空隙中，以全组合（非全排列）方式插入n-1（如下less）次向右走
    // 结果是：C_{m+n-2}^{n-1} = C_{total}^{less}
    int less = ((m < n) ? m : n) - 1;
    // for循环less次，公式求解
    // 公式分子（less项）：total(total-1)(total-2)...(total-less+1)
    // 公式分母(less项）：less(less-1)(less-2)...1
    for (int i = 1; i <= less; i++) 
        ans = ans * (total - less + i) / i;
    return ans;
}
```
