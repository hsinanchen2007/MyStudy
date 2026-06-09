```
class Solution {
public:
    const int INF = 1e8;
    int min3(int x, int y, int z) {
        return min(min(x, y), z);
    }
    int minFallingPathSum(vector<vector<int>>& A) {
        int N = A.size();
        int M = A[0].size();
        vector<int> dp1(M + 2, 0);
        vector<int> dp2(M + 2, INF);
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                dp2[j] = min3(dp1[j - 1], dp1[j], dp1[j + 1]) + A[i - 1][j - 1];
            }
            swap(dp1, dp2);
            fill(dp2.begin(), dp2.end(), INF);
        }
        return *min_element(dp1.begin(), dp1.end());
    }
};
```

![image.png](https://pic.leetcode-cn.com/6bbcab0bfa2b612466ffbec23551596a8756b61ee693fabbf77e0dbb34a9a2ed-image.png)

