# 解法一：
动态规划
1，变量定义
`dp[2][2]:`
`dp[0][0]`代表对于当前列，上方不铺，下方不铺的情况数
`dp[0][1]`代表对于当前列，上方不铺，下方铺的情况数
`dp[1][0]`代表对于当前列，上方铺，下方不铺的情况数
`dp[1][1]`代表对于当前列，上方铺，下方铺的情况数
2，状态转移方程：
`dp1`为当前列，`dp`为上一列
`dp1[0][0] = dp[1][1]`
`dp1[0][1] = dp[0][0] + dp[1][0]`
`dp1[1][0] = dp[0][0] + dp[0][1]`
`dp1[1][1] = dp[0][0] + dp[1][0] + dp[0][1] + dp[1][1]`
时间复杂度：`O(n)`
```C++ []
class Solution {
public:
    const long M = 1e9 + 7;
    int numTilings(int N) {
        long dp[2][2] = {{1, 0}, {0, 1}};
        for (int i = 2; i <= N; ++i) {
            long dp1[2][2] = {{0, 0}, {0, 0}};
            dp1[0][0] = dp[1][1] % M;
            dp1[0][1] = (dp[0][0] + dp[1][0]) % M;
            dp1[1][0] = (dp[0][0] + dp[0][1]) % M;
            dp1[1][1] = (dp[0][0] + dp[1][0] + dp[0][1] + dp[1][1]) % M;
            swap(dp1, dp);
        }
        return dp[1][1];
    }
};
```
![image.png](https://pic.leetcode-cn.com/bd980f23e80ab07c65db2839cadaac2ae41ff18c2ff0409bb95159508bf2bf73-image.png)

# 解法二
状态转移矩阵快速幂运算
1，将状态转移方程写成状态转移矩阵，转移矩阵见代码，变量的排布方式与解法一相同，可以对照着看
2，矩阵快速幂运算
可以在`O(log(n))`时间复杂度得到结果
```C++ []
class Solution {
public:
    const long M = 1e9 + 7;
    vector<vector<long> > matrixMulti(const vector<vector<long> >& m1, const vector<vector<long> >& m2) {
        vector<vector<long> > m(m1.size(), vector<long>(m2[0].size(), 0));
        for (int i = 0; i < m1.size(); ++i) {
            for (int j = 0; j < m2[0].size(); ++j) {
                for (int k = 0; k < m2.size(); ++k) {
                    m[i][j] += m1[i][k] * m2[k][j];
                    m[i][j] %= M;
                }
            }
        }
        return m;
    }
    int numTilings(int N) {
        vector<vector<long> > m {{1, 0, 0, 1}};
        vector<vector<long> > trans{
            {0, 1, 1, 1},
            {0, 0, 1, 1},
            {0, 1, 0, 1},
            {1, 0, 0, 1}};
        N -= 1;
        for (; N != 0; N >>= 1) {
            if (N & 1) {
                m = matrixMulti(m, trans);
            }
            trans = matrixMulti(trans, trans);
        }
        return m[0][3];
    }
};
```

![image.png](https://pic.leetcode-cn.com/2be8fa6e350412f573733d6433ff75ab67c035c922806f099f3b888fe0fc4daf-image.png)
