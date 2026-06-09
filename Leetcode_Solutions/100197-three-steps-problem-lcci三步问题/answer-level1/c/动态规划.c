### 解题思路
dp[i]=dp[i-1]+dp[i-2]+dp[i-3]

### 代码

```c
//#define   max(a,b)  ((a)>(b)?(a):(b))
//#define   MAX(a,b,c)  ((c)>max(a,b)?(c):max(a,b))


int waysToStep(int n){
unsigned int dp[n+3];
dp[1]=1;
dp[2]=2;
dp[3]=4;
for(int i=4;i<=n;i++){
dp[i]=dp[i-3]+dp[i-2]+dp[i-1];
dp[i]%=1000000007;
}
return dp[n];
}
```