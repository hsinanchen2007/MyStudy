**方法一：**
类似于多重背包，硬币无限个，`dp[i][j]`表示加入第`i`种硬币时硬币总数为`j`的表示法数，那么对于每种硬币(假设第`i`种硬币的价值为`v[i]`)而言，状态转移方程就为`dp[i][j] = dp[i-1][j] + dp[i][j-v[i]]`。表示当前方法数可以由之前所有`i-1`种硬币的方法数加上放第`i`种硬币的方法数得到。
时间复杂度O(N)，空间复杂度O(N^2)，可以优化一下空间成O(N)。
```cpp
int waysToChange(int n) {
    const int mod = 1e9 + 7;
    vector<int> dp(n + 1), v;
    dp[0] = 1;
    v.push_back(1), v.push_back(5), v.push_back(10), v.push_back(25);
    for(int i = 0; i < v.size(); ++ i) {
        for(int j = v[i]; j <= n; ++ j) {
            dp[j] = (dp[j] + dp[j - v[i]]) % mod;
        }
    }
    return dp[n];
}
```
