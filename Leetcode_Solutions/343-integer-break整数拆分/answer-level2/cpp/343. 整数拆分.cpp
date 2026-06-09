### 解题思路
典型的暴力深搜不成加记忆化包过的练手题~

### 代码

```cpp
class Solution {
public:
    int integerBreak(int n) {
        int dp[55]={0};
        return dfs(n,dp);
    }
    inline int dfs(int x,int dp[])
    {
        int  ans=-1;
        if(x<=1)return x;
        if(dp[x])return dp[x];
        for(int i=1;i<x;i++)ans=max(max(dfs(i,dp)*(x-i),i*(x-i)),ans);
        dp[x]=ans;
        return ans;
    }
};
```