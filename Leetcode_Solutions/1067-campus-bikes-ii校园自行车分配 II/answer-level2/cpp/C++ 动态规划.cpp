```
class Solution {
public:
    int abs(int x) {
        return (x > 0) ? x : -x;
    }
    int manhattan(const vector<int>& v1, const vector<int>& v2) {
        return abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]);
    }
    const int INF = 1000000;
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int R = workers.size();
        int C = bikes.size();
        vector<vector<int> > dist(R, vector<int>(C, 0));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                dist[i][j] = manhattan(workers[i], bikes[j]);
            }
        }
        int N = 1 << R;
        int M = 1 << C;
        vector<vector<int> > dp(N, vector<int>(M, INF));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                dp[1 << i][1 << j] = dist[i][j];
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int k, l, m, n;
                k = i;
                l = j;
                m = k & (~k + 1);
                n = l & (~l + 1);
                while (n > 0) {
                    dp[i][j] = min(dp[i][j], dp[i - m][j - n] + dp[m][n]);
                    l -= n;
                    n = l & (~l + 1);
                }
                k = i;
                l = j;
                m = k & (~k + 1);
                n = l & (~l + 1);
                while (m > 0) {
                    dp[i][j] = min(dp[i][j], dp[i - m][j - n] + dp[m][n]);
                    k -= m;
                    m = k & (~k + 1);
                }
            }
        }
        int res = INF;
        for (int i = 0; i < M; ++i) {
            res = min(res, dp[N - 1][i]);
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/ab08cf7e66642986bb39da9d6d1f48be4e03c847b88b9081234bfc58352e3406-image.png)
