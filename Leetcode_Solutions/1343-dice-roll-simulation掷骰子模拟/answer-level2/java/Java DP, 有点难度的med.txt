拿到题很容易看出是DP，求多少个值或最值问题，要么贪心、搜索、排列组合，要么DP。这里明显用dp。
f[i][j][k] 表示第 i 次掷骰子，当前面 j，连续出现 k 次。

显然，若 k > 1，那么 f[i][j][k] = f[i - 1][j][k - 1]，上一次也必须扔了 j。
若 k == 1，那么当前由所有非 j 转移过来。因此每次都要对 i - 1 次投掷的非 j 所有连续次数求和。
当 i == 1 时，f[i][j][k] = 1，特判一下，也是个初始化条件。

```java
class Solution {
    public int dieSimulator(int n, int[] rollMax) {
        int[][][] f = new int[n + 1][7][16];
        for (int i = 0; i < 7; i ++) Arrays.fill(f[0][i], 1);
        int M = 1000000007;
        int res = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = 0; j < 6; j ++) {
                if (i == 1) {
                    f[i][j][1] = 1;
                    continue;
                }
                for (int k = 1; k <= rollMax[j]; k ++) {
                    if (k > 1) f[i][j][k] = f[i - 1][j][k - 1] % M;
                    else {
                        int sum = 0;
                        for (int jj = 0; jj < 6; jj ++) {
                            if (jj == j) continue;
                            for (int kk = 1; kk <= rollMax[jj]; kk ++) sum = (sum + f[i - 1][jj][kk]) % M;
                        }
                        f[i][j][k] = sum;
                    }
                }
            }
        }
        for (int j = 0; j < 6; j ++) for (int k = 1; k <= rollMax[j]; k ++) res = (res + f[n][j][k]) % M;
        return res;
    }
}
```