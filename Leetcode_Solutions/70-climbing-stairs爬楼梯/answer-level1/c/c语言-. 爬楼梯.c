### 解题思路
动态规划
爬到第i层=爬到第i-1层在向上爬一层+爬到i-2层在向上爬2层
dp[i]=dp[i-1]+dp[i-2]

### 代码

```c
int climbStairs(int n){
          int *a=(int *)malloc(sizeof(int)*1000);
           int i;
           a[1]=1;
           a[2]=2;
           for(i=3;i<=n;i++)a[i]=a[i-1]+a[i-2];
           return a[n];
}
```