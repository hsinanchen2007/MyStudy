### 解题思路
递归 + 检查是否有重复计算：记录重复计算值，直接返回

### 代码

```c

int g_dp[1001][1001];
#define MAGIC 0x55555555

int dfs(char *s, int i, int j) {
    if (i > j) {
        return 0;
    }
    if (i == j) {
        return 1;
    }
    
    if (g_dp[i][j] != MAGIC) {
        return g_dp[i][j];
    }

    int ret;
    if (s[i] == s[j]) {
        ret = dfs(s, i + 1, j - 1)  + 2;
    } else {
        int t1 = dfs(s, i + 1, j);
        int t2 = dfs(s, i, j - 1);
        ret = t1 > t2 ? t1 : t2;
    }

    g_dp[i][j] = ret;
    return ret;
}

int longestPalindromeSubseq(char * s) {
    if (s == NULL) {
        return NULL;
    }

    memset(g_dp, 0x55, sizeof(g_dp));
    return dfs(s, 0, strlen(s) - 1);
}

```