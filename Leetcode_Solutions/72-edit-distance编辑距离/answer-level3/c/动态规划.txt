### 解题思路
    打卡学习 ~ ~ ~
    日常膜拜大佬们的思路与代码
### 代码

```c
int min(int a,int b){
    return a < b ? a : b;
}
int minDistance(char * word1, char * word2){
    int m = strlen(word1),n = strlen(word2);
    int dp[m+1][n+1];
    for(int i = 0;i <= m;i++) dp[i][0] = i;
    for(int j = 0;j <= n;j++) dp[0][j] = j;
    for(int i = 1;i <= m;i++)
        for(int j = 1;j <= n;j++)
            dp[i][j] = min(dp[i-1][j-1] + (int)(word1[i-1] != word2[j-1]),min(dp[i-1][j],dp[i][j-1]) + 1);
    return dp[m][n];
}
```