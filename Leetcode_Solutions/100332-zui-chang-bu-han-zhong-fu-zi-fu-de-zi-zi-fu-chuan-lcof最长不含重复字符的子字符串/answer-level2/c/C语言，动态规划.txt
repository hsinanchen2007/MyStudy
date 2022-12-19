### 解题思路
此处撰写解题思路
dp表示以i结尾的最长不含重复字串的字符串长度， position表示每个字符上次出现在字符串中的位置的下标；
（1）如果该字符在以前没有出现过，则dp[i]长度+1且更新position的位置；
（2）如果该字符在之前出现过，则计算差距
    2.1 如果两个字符之间的差距<=dp[i-1]，则dp[i]的长度就是dif
    2.2 如果两个字符之间的差距>dp[i-1]，则dp[i]的长度就是dp[i - 1] + 1

### 代码

```c
#define MAX_HTL(a, b) ((a) > (b) ? (a) : (b))
#define NUM 256

int lengthOfLongestSubstring(char* s){
    int maxLen = 1;
    int i, sz, diff;
    /* 
     *   position表示每个字符上次出现在字符串中的位置的下标
     *   dp表示以i结尾的最长不含重复字串的字符串长度 
    */
    int *position, *dp;

    sz = strlen(s);
//printf("0__sz = %d\n", sz);
    if (sz <= 1) {
        return sz;
    }
    
    dp = (int *)malloc(sizeof(int) * sz);
    position = (int *)malloc(sizeof(int) * NUM);
    memset(position, -1, sizeof(int) * NUM);
    memset(dp, 0, sizeof(int) * sz);

    dp[0] = 1;
    position[s[0]] = 0;
    for (i = 1; i < sz; i++) {
        /* 如果该字符在以前没有出现过，则dp[i]长度+1且更新position的位置 */
        if (position[s[i]] == -1) {
            dp[i] = dp[i - 1] + 1;
//printf("1__s[%d] = %c, dp[%d] = %d\n", i, s[i], i, dp[i]);
        } else {
            /* 如果该字符在之前出现过，则计算差距 */
            diff = i - position[s[i]];
            /* 如果两个字符之间的差距<=dp[i-1]，则dp[i]的长度就是diff，否则就是dp[i - 1] + 1 */
            if (diff <= dp[i - 1]) {
                dp[i] = diff;
//printf("2__s[%d] = %c, dp[%d] = %d\n", i, s[i], i, dp[i]);
            } else {
                dp[i] = dp[i - 1] + 1;
//printf("3__s[%d] = %c, dp[%d] = %d\n", i, s[i], i, dp[i]);
            }
        }
        position[s[i]] = i;
        maxLen = MAX_HTL(maxLen, dp[i]);
    }

    free(dp);
    return maxLen;
}
```