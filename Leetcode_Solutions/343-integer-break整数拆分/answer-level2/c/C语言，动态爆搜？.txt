```cpp
int integerBreak(int n){
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    for(int i=3;i<=n;i++)
    {
        dp[i]=INT_MIN;
        for(int j=1;j<i;j++)
        {
            int max=(j*(i-j))>(j*(dp[i-j]))?(j*(i-j)):(j*(dp[i-j]));
            dp[i]=max>dp[i]?max:dp[i];
        }
    }
    return dp[n];
}
```
就是列举了所有情况。
这几天回书本了，写得少。