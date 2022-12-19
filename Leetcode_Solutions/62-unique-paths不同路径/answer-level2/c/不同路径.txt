### 解题思路
这道题感觉和那个最小路径和的思路没区别，就是区分边界和非边界的情况：
边界就一直是一种，非边界就用左边和上边的相加即可。

### 代码

```c
int uniquePaths(int m, int n){
    int dp[m][n];

    int i,j;

    for(i = 0;i < m;i++){
        for(j = 0;j < n;j++){
            if(i == 0 && j == 0){
                dp[i][j] = 1;
            }

            else if(i == 0){
                dp[i][j] = 1;
            }

            else if(j == 0){
                dp[i][j] = 1;
            }

            else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    return dp[m-1][n-1];

}
```