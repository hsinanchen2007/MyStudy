### 解题思路
此处撰写解题思路

### 代码

```c
int dp[1000][1000] = {0};
int countSubstrings(char *s)
{
    int i, j;
    int len = strlen(s);
    int res = 0;
    memset(dp, 0, sizeof(dp));
 
    for (j = 0; j < len; j++) {
        for (i = 0; i <=j; i++) {
            if (s[i] == s[j] && (j-i <=2 || dp[i+1][j-1])) {
                dp[i][j] = 1;
                res++;
            }     
        }
    }
    return res;
}

```