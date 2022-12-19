```
class Solution {
public:
    const int INF = 1e9;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        K = min(K, n - 2);
        vector<long> dp(n, INF);
        dp[src] = 0;
        for (int k = 0; k <= K; ++k) {
            vector<long> dp1 = dp;
            for(auto& e: flights) {
                dp1[e[1]] = min(dp1[e[1]], dp[e[0]] + e[2]);
            }
            swap(dp1, dp);
        }
        return dp[dst] == INF ? -1 : dp[dst];
    }
};
```

![image.png](https://pic.leetcode-cn.com/f53af497ac2ed5058a63de778bb566cd0abcb46a41666c18fcc351b27618cfdd-image.png)
