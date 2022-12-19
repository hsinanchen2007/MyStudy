```
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        int N = A.size();
        vector<map<long, int> > dp(N);
        dp[1][(long)A[1] - (long)A[0]] = 1;
        int res = 0;
        for (int i = 2; i < A.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                long d = (long)A[i] - (long)A[j];
                ++dp[i][d];
                if (dp[j].count(d)) {
                    dp[i][d] += dp[j][d];
                    res += dp[j][d];
                }
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/3672f66b70e1ba9e1f639deae4549bb09523ff1afc1d170b35c6b559b31b2c51-image.png)
