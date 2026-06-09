### 解题思路

定义dp[i][j]表示字符串s1[0...i]和字符串s2[0...j]的最小ASCII删除和
- 当`i = 0, j = 0`时
  dp[0][0] = 0 (无须删除任何字符)
- 当`i = 0, 1 <= j <= strlen(s2)` 时 
  dp[0][j] = dp[0][j - 1] + s2[j - 1] (删除s2[j-1])
- 当`1 <= i <= strlen(s1), j = 0`时
  dp[i][0] = dp[i - 1][0] + s1[i - 1] (删除s1[i-1])
- 当`1 <= i <= strlen(s1), 1 <= j <= strlen(s2)`时
  dp[i][j] = Min(dp[i][j - 1] + s2[j - 1], dp[i - 1][j] + s1[i - 1], dp[i - 1][j - 1] + s1[i - 1] + s2[j - 1])

### 代码

```c
#define MAX_SIZE 2000

int Min(int a, int b)
{
    return a > b ? b : a;
}

int minimumDeleteSum(char * s1, char * s2){
    
    int dp[MAX_SIZE][MAX_SIZE] = {0};
    dp[0][0] = 0; 
    
    for (int i = 1; i <= strlen(s1); i++) {
        dp[i][0] = dp[i - 1][0] + s1[i - 1];
    }
    
    for (int j = 1; j <= strlen(s2); j++) {
        dp[0][j] = dp[0][j - 1] + s2[j - 1];
    }
    
    
    for (int i = 1; i <= strlen(s1); i++) {
        for (int j = 1; j <= strlen(s2); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];    
            } else {
                dp[i][j] = Min(dp[i - 1][j] + s1[i - 1], Min(dp[i][j - 1] + s2[j - 1], dp[i - 1][j - 1] + s1[i - 1] + s2[j - 1]));
            }
            //printf("%d %d %d\n", i, j, dp[i][j]);
        }
    }
    
    return dp[strlen(s1)][strlen(s2)];    

}
```