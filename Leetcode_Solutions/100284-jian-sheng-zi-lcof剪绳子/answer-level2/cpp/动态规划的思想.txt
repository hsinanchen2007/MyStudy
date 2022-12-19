我们用dp[i]来表示和为i的数组的最优值，那么

dp[i]=max(dp[i],max((i-k)*k),(i-k)*dp[k]);

即k可以分（dp[k]）,也可以不分（k）

从而可以求得最大值

```
class Solution {
public:
    int cuttingRope(int n) {
           vector<int> dp(n+1,0);
           dp[1]=1;
           dp[2]=1;
           for(int i=3;i<=n;i++)
           {
               for(int k=2;k<=i-1;k++)
               {
                   dp[i]=max(dp[i],max((i-k)*k,(i-k)*dp[k]));
               }
           }
           return dp[n];
    }
};
```
