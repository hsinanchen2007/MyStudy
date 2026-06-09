```
int longestLine(vector<vector<int>>& M) {
    if (M.empty() || M[0].empty()) return 0;
    int dp[M[0].size()+2][3];
    memset(dp, 0, sizeof(dp));
    int res = 0;
    for (int i = 1; i <= M.size(); i++) {
        int count = 0;
        int prev = dp[0][1];
        for (int j = 1; j <= M[0].size(); j++) {
            int temp = dp[j][1];
            if (M[i-1][j-1] == 1) {
                ++count;
                dp[j][0] = dp[j][0]+1;
                dp[j][1] = prev+1;
                dp[j][2] = dp[j+1][2]+1;
                res = max({res, count, dp[j][0], dp[j][1], dp[j][2]});
            } else {
                count = dp[j][0] = dp[j][1] = dp[j][2] = 0;
            }
            prev = temp;
        }
    }
    return res;
}
```
