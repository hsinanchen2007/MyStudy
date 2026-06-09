```c
#define SIZE 105
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

int dp[SIZE][SIZE];

int Dfs(const char* s, int left, int right)
{
    if (left > right) {
        return 0;
    }
    if (left == right) {
        return 1;
    }
    if (dp[left][right]) {
        return dp[left][right];
    }
    int ans = Dfs(s, left + 1, right) + 1;
    int i;
    for (i = left + 1; i <= right; ++i) {
        if (s[left] == s[i]) {
           ans = MIN(ans, Dfs(s, left, i - 1) + Dfs(s, i + 1, right));
        }
    }
    dp[left][right] = ans;
    return ans;
}

int strangePrinter(char * s){
    if (s == NULL || *s == '\0') {
        return 0;
    }
    memset(dp, 0, sizeof(dp));
    return Dfs(s, 0, strlen(s) - 1);
}

```