dp[i][j]为区间[i, j]的多边形最小值题解
这样就有了递推公式：
**dp[i][j] = min{dp[i][k] + dp[k][j] + A[i][k][j]} for all k in range (i, j)**
```
class Solution {
public:
    const int INF = 1000000;
    int minScoreTriangulation(vector<int>& A) {
        int N = A.size();
        vector<vector<int> > dp(N, vector<int>(N, INF));
        for (int i = 0; i < N; ++i) {
            dp[i][(i + 1) % N] = 0; // 两个点构不成三角形，初始化为0
        }
        for (int len = 2; len < N; ++len) {
            for (int i = 0; i < N; ++i) {
                int j = (i + len) % N;
                for (int k = (i + 1) % N; k != j; k = (k + 1) % N) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i]* A[k] * A[j]);
                }
            }
        }
        return dp[0][N - 1];
    }
};
```
![image.png](https://pic.leetcode-cn.com/147eb1321c12b5ec43218b6f145ec122913f3baf5f7efb5f5b17c360f36b6edf-image.png)
