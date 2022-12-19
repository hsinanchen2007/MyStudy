```
/**
 * 背包问题：https://github.com/tianyicui/pack
 * 一维背包的变体，其实本质是一样的：一维背包的优化空间之后的算法伪代码如下（V为容积，N为物品数量，C为cost，W为value）：
 * F [0..V] ← 0
 *   for i ← 1 to N
 *     forv ← V to Ci (注意这里是倒序，因为F[i, v] 需要F[i-1, v-Ci]进行推导，如果顺序F[v-Ci]就是F[i, v-Ci])
 *       F[v] ← max{F[v],F[v−Ci]+Wi}
 * 类似的，对于本题，状态转移方程应该是：dp[j, k] = max{dp[j, k], dp[j-count0, k-count1] + 1}
**/
int findMaxForm(char ** strs, int strsSize, int m, int n) {
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(int) * (m + 1) * (n + 1));
    for (int i = 0; i < strsSize; ++i) {
        int count0 = 0;
        int count1 = 0;
        char *str = strs[i];
        while (*str != '\0') {
            if (*str == '0') {
                ++count0;
            } else {
                ++count1;
            }
            ++str;
        }
        
        for (int j = m; j >= count0; --j) {
            for (int k = n; k >= count1; --k) {
                int tmp = dp[j - count0][k - count1] + 1;
                if (tmp > dp[j][k]) {
                    dp[j][k] = tmp;
                }
            }
        }
    }
    
    return dp[m][n];
}

```
