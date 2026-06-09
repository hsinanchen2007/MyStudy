动态规划的思想：dp[k][i]表示前i个字符分割为k段时最少修改字符数, 那么dp[k][i] = MIN{dp[k - 1][t] + cost(s[t + 1~i])};
其中cost(s[t + 1~i])表示t + 1 : i之间组成回文串需要修改的字符数；
```
// 动态规划
// dp[k][i]表示前i个字符分为k段的所需修改的最少字符数
// dp[k][i] = MIN(dp[k - 1][t] + cost(s[t + 1~i]))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX_INT 0x0FFFFFFF
#define MAX_LEN 100
int g_dp[MAX_LEN + 1][MAX_LEN + 1];
int g_dpMin[MAX_LEN + 1][MAX_LEN + 1];
void CalcMinChange(char *s, int len)
{
    int i, j, k;
    int l, r;
    int count = 0;
    for (i = 1; i < len; i++) {
        g_dpMin[i - 1][i] = (s[i - 1] == s[i] ? 0 : 1);
    }
    for (k = 2; k <= len; k++) {
        for (i = 0; i < len - k + 1; i++) {
            j = i + k;
            if (j >= len) {
                break;
            }
            l = i;
            r = j;
            count = 0;
            while (l < r) {
                if (s[l] != s[r]) {
                    count++;
                }
                l++;
                r--;
            }
            g_dpMin[i][j] = count;
        }
    }
}
int palindromePartition(char * s, int k){
    int i, j, t;
    int len = strlen(s);
    if (k >= len || len <= 0 || k <= 0) {
        return 0;
    }
    (void)memset(g_dp, 0, sizeof(g_dp));
    (void)memset(g_dpMin, 0, sizeof(g_dpMin));
    CalcMinChange(s, len);
    for (i = 1; i < len; i++) {
        g_dp[1][i] = g_dpMin[0][i];
    }
    for (t = 2; t <= k; t++) {
        for (i = t - 1; i < len; i++) {
            g_dp[t][i] = MAX_INT;
            for (j = t - 2; j < i; j++) {
                g_dp[t][i] = MIN(g_dp[t][i], g_dp[t - 1][j] + g_dpMin[j + 1][i]);
            }
        }
    }
    return g_dp[k][len - 1];
}
```
