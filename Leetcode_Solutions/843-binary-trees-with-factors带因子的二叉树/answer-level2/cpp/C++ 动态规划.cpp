# 思路：
1，先对数组进行从小到大排序，保证任何数的因子若存在则一定出现在其左边
2，`dp[i]`代表以第`i`个数为根结点的树的数目
3，状态转移方程为：
`dp[i] = 1 + sum{dp[a] * dp[b] | for all (a, b) if (A[a] * A[b] == A[i])} `
```C++ []
class Solution {
public:
    const long M = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& A) {
        sort(A.begin(), A.end());
        int N = A.size();
        vector<long> dp(N, 1);
        unordered_map<int, int> m;
        m[A[0]] = 0;
        long res = dp[0];
        for (int i = 1; i < N; ++i) {
            for (auto& p : m) {
                if (A[i] % p.first == 0 && m.count(A[i] / p.first)) {
                    dp[i] += dp[p.second] * dp[m[A[i] / p.first]];
                    dp[i] %= M;
                }
            }
            res += dp[i];
            res %= M;
            m[A[i]] = i;
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/af34e7a97539c39e05cba1f2b50d669b88b1c3a739a5610204fe64f258e0a461-image.png)

