状态压缩动态规划
`dp[i] 代表在该周呆在i城市的最大休假天数`
```c++ []
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int N = flights.size();
        int K = days[0].size();
        vector<int> dp(N, 0);
        dp[0] = 1;
        for (int k = 0; k < K; ++k) {
            vector<int> dp1(N, 0);
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (dp[j] > 0 && (i == j || flights[j][i] == 1)) {
                        dp1[i] = max(dp1[i], dp[j] + days[i][k]);
                    }
                }
            }
            swap(dp, dp1);
        }
        return *max_element(dp.begin(), dp.end()) - 1;
    }
};
```

![image.png](https://pic.leetcode-cn.com/60f72ab1d90ad5a29090aa2d18c238252833420824c28e4a87960a9a6351fd7e-image.png)
