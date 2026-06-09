### 解题思路
此处撰写解题思路

dp[l][r] 表示字符串中从 l 开始到 r 是否为字符串
判断回文串：
1. 当 r - l <= 2, 只需要判断 s[l] == s[r], 如 a, aa, aba
2. 当 r - l > 2，需要判断 s[l] == s[r] 且  dp[l + 1][r - 1] == 1, 即内一层也必须是回文串


### 代码

```c
#define MAX_NUM 1001

int countSubstrings(char * s){
    if (!s || strlen(s) == 0) {
        return 0;
    }
    if (strlen(s) == 1) {
        return 1;
    }
    int dp[MAX_NUM][MAX_NUM] = {0};
    int len = strlen(s);
    int sum = 0;
    for (int r = 0; r < len; r++) {
        for (int l = 0; l <= r; l++) {
            if (s[l] == s[r] && (r - l <= 2 || dp[l + 1][r - 1])) {
                dp[l][r] = 1;
                sum += 1;
            }
        }
    }

    return sum;
}
```